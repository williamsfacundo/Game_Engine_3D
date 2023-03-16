#pragma once

#include "Renderer.h"


	class Texture
	{

	private:
		unsigned int m_RendererID;
		std::string m_FilePath;
		unsigned char* m_LocalBuffer;
		int m_Width, m_Height, m_BPP;

	public:
		DllExport Texture(const std::string& path);
		DllExport ~Texture();

		DllExport void Bind(unsigned int slot = 0) const;
		DllExport void UnBind() const;

		DllExport inline int GetWidth() const { return m_Width; }
		DllExport inline int GetHeight() const { return m_Height; }

	};

