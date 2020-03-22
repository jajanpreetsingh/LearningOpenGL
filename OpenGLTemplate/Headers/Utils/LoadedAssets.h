#pragma once

#include <map>
#include <string>

enum class ShaderType
{
	Tris_Vert,
	Tris_Frag
};

class LoadedAssets
{
private:

	static std::map<ShaderType, std::string> ShaderSources;

	void Init();

	void LoadShader(ShaderType key, std::string filename);

public:

	LoadedAssets();

	static std::string GetShader(ShaderType key);

	~LoadedAssets();
};