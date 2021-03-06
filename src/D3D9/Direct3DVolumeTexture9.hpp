// Copyright 2016 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef D3D9_Direct3DVolumeTexture9_hpp
#define D3D9_Direct3DVolumeTexture9_hpp

#include "Direct3DBaseTexture9.hpp"

#include "Config.hpp"

#include <d3d9.h>

namespace D3D9
{
	class Direct3DVolume9;

	class Direct3DVolumeTexture9 : public IDirect3DVolumeTexture9, public Direct3DBaseTexture9
	{
	public:
		Direct3DVolumeTexture9(Direct3DDevice9 *device, unsigned int width, unsigned int height, unsigned int depth, unsigned int levels, unsigned long usage, D3DFORMAT format, D3DPOOL pool);

		~Direct3DVolumeTexture9() override;

		// IUnknown methods
		long __stdcall QueryInterface(const IID &iid, void **object) override;
		unsigned long __stdcall AddRef() override;
		unsigned long __stdcall Release() override;

		// IDirect3DResource9 methods
		long __stdcall GetDevice(IDirect3DDevice9 **device) override;
		long __stdcall SetPrivateData(const GUID &guid, const void *data, unsigned long size, unsigned long flags) override;
		long __stdcall GetPrivateData(const GUID &guid, void *data, unsigned long *size) override;
		long __stdcall FreePrivateData(const GUID &guid) override;
		unsigned long __stdcall SetPriority(unsigned long newPriority) override;
		unsigned long __stdcall GetPriority() override;
		void __stdcall PreLoad() override;
		D3DRESOURCETYPE __stdcall GetType() override;

		// IDirect3DBaseTexture9 methods
		unsigned long __stdcall SetLOD(unsigned long newLOD) override;
		unsigned long __stdcall GetLOD() override;
		unsigned long __stdcall GetLevelCount() override;
		long __stdcall SetAutoGenFilterType(D3DTEXTUREFILTERTYPE filterType) override;
		D3DTEXTUREFILTERTYPE __stdcall GetAutoGenFilterType() override;
		void __stdcall GenerateMipSubLevels() override;

		// IDirect3DVolumeTexture9 methods
		long __stdcall GetLevelDesc(unsigned int level, D3DVOLUME_DESC *description) override;
		long __stdcall GetVolumeLevel(unsigned int level, IDirect3DVolume9 **volume) override;
		long __stdcall LockBox(unsigned int level, D3DLOCKED_BOX *lockedVolume, const D3DBOX *box, unsigned long flags) override;
		long __stdcall UnlockBox(unsigned int level) override;
		long __stdcall AddDirtyBox(const D3DBOX *dirtyBox) override;

		// Internal methods
		Direct3DVolume9 *getInternalVolumeLevel(unsigned int level);

	private:
		// Creation parameters
		const unsigned int width;
		const unsigned int height;
		const unsigned int depth;

		Direct3DVolume9 *volumeLevel[sw::MIPMAP_LEVELS];
	};
}

#endif // D3D9_Direct3DVolumeTexture9_hpp
