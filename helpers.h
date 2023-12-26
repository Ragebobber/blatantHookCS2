#pragma once

using oD3D11CreateDeviceAndSwapChain = HRESULT(__stdcall*)(IDXGIAdapter* pAdapter,
	D3D_DRIVER_TYPE            DriverType,
	HMODULE                    Software,
	UINT                       Flags,
	const D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT                       FeatureLevels,
	UINT                       SDKVersion,
	const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
	IDXGISwapChain** ppSwapChain,
	ID3D11Device** ppDevice,
	D3D_FEATURE_LEVEL* pFeatureLevel,
	ID3D11DeviceContext** ppImmediateContext
	);

class Helpers
{
public:
	Helpers();
	~Helpers();

	static std::uint8_t* getAbsolute(std::uint8_t* address, std::uint32_t rvaOffset, std::uint32_t ripOffset)
	{
		if (!address || !rvaOffset || !ripOffset)
		{
			return nullptr;
		}

		std::uint32_t rva = *reinterpret_cast<std::uint32_t*>(address + rvaOffset);
		std::uint64_t rip = reinterpret_cast<std::uint64_t>(address) + ripOffset;

		return reinterpret_cast<std::uint8_t*>(rva + rip);
	}

	template<typename T>
	static 	T* getInterface(const char* moduleName, const char* interfaceName) {
		if (!moduleName || !interfaceName)
		{
			return nullptr;
		}
		HMODULE module = GetModuleHandle(moduleName);

		if (!module)
		{
			return nullptr;
		}

		std::uint8_t* createInterface = reinterpret_cast<std::uint8_t*>(GetProcAddress(module, "CreateInterface"));
		if (!createInterface)
		{
			return nullptr;
		}

		using interface—allback_t = void* (__cdecl*)();

		typedef struct _interfaceReg
		{
			interface—allback_t callback;
			const char* name;
			_interfaceReg* flink;
		} interfaceReg_t;

		interfaceReg_t* interfaceList = *reinterpret_cast<interfaceReg_t**>(getAbsolute(createInterface, 3, 7));
		if (!interfaceList)
		{
			return nullptr;
		}
		for (_interfaceReg* it = interfaceList; it; it = it->flink)
		{
			if (!strcmp(it->name, interfaceName))
			{
				return reinterpret_cast<T*>(it->callback());
			}
		}

		return nullptr;

	}

	template <typename T>
	static	T GetVFunc(void* vTable, int iIndex) {
		return (*(T**)vTable)[iIndex];
	}

	static std::vector<std::uint32_t> pattern2Byte(const char* pattern)
	{
		std::vector<std::uint32_t> bytes;
		char* start = const_cast<char*>(pattern);
		char* end = const_cast<char*>(pattern) + std::strlen(pattern);

		for (char* current = start; current < end; current++)
		{
			if (*current == '?')
			{
				current++;

				if (*current == '?')
				{
					current++;
				}

				bytes.push_back(-1);
			}
			else
			{
				bytes.push_back(std::strtoul(current, &current, 16));
			}
		}

		return bytes;
	}

	static std::uint8_t* patternScan(const char* module_name, const char* signature)
	{
		HMODULE module_handle = GetModuleHandle(module_name);

		if (!module_handle)
		{
			return nullptr;
		}

		PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
		PIMAGE_NT_HEADERS nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t*>(module_handle) + dos_header->e_lfanew);

		std::size_t size_of_image = nt_headers->OptionalHeader.SizeOfImage;
		std::vector<std::uint32_t> pattern_bytes = pattern2Byte(signature);
		std::uint8_t* image_base = reinterpret_cast<std::uint8_t*>(module_handle);

		std::size_t pattern_size = pattern_bytes.size();
		std::uint32_t* array_of_bytes = pattern_bytes.data();

		for (std::size_t i = 0; i < size_of_image - pattern_size; i++)
		{
			bool found = true;

			for (std::size_t j = 0; j < pattern_size; j++)
			{
				if (image_base[i + j] != array_of_bytes[j] && array_of_bytes[j] != -1)
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				return &image_base[i];
			}
		}

		return nullptr;
	}


	static void** getSwapChain() {
		HMODULE libD3D11 = GetModuleHandleA("d3d11.dll");
		if (!libD3D11)
			return nullptr;

		oD3D11CreateDeviceAndSwapChain D3D11CreateDeviceAndSwapChain = (oD3D11CreateDeviceAndSwapChain)GetProcAddress(libD3D11, "D3D11CreateDeviceAndSwapChain");
		if (!D3D11CreateDeviceAndSwapChain)
			return nullptr;

		D3D_FEATURE_LEVEL featureLevel;
		const D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0 };

		DXGI_RATIONAL refreshRate;
		refreshRate.Numerator = 60;
		refreshRate.Denominator = 1;

		DXGI_MODE_DESC bufferDesc;
		bufferDesc.Width = 100;
		bufferDesc.Height = 100;
		bufferDesc.RefreshRate = refreshRate;
		bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		DXGI_SAMPLE_DESC sampleDesc;
		sampleDesc.Count = 1;
		sampleDesc.Quality = 0;

		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		swapChainDesc.BufferDesc = bufferDesc;
		swapChainDesc.SampleDesc = sampleDesc;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 1;
		swapChainDesc.OutputWindow = GetForegroundWindow();
		swapChainDesc.Windowed = 1;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		IDXGISwapChain* swapChain;
		ID3D11Device* device;
		ID3D11DeviceContext* context;

		HRESULT call = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, 1, D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel, &context);

		if (FAILED(call))
			return nullptr;

		void** pVMT = *(void***)swapChain;

		swapChain->Release();
		device->Release();
		context->Release();

		return pVMT;
	}

	template <typename T = void*>
	static T GetVMethod(uint32_t uIndex, void* pClass) {
		if (!pClass) {			
			return T{};
		}

		void** pVTable = *static_cast<void***>(pClass);
		if (!pVTable) {	
			return T{};
		}

		return reinterpret_cast<T>(pVTable[uIndex]);
	}

	static constexpr uint32_t fnv1aHash(const char* str) noexcept { return (*str ? (fnv1aHash(str + 1) ^ *str) * 0x01000193 : 0x811c9dc5); }

	template <std::size_t Index, typename ReturnType, typename... Args>
	static ReturnType CallVirtual(void* instance, Args... args) {
		using Fn = ReturnType(__thiscall*)(void*, Args...);

		auto function = (*reinterpret_cast<Fn**>(instance))[Index];
		return function(instance, args...);
	}
	
private:

};
