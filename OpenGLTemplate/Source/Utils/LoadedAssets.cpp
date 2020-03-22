#pragma once

#include "Utils/LoadedAssets.h"
#include <fstream>
#include <Common/Constants.h>


std::map<ShaderType, std::string> LoadedAssets::ShaderSources;
LoadedAssets::LoadedAssets()
{
	Init();
}

void LoadedAssets::Init()
{
	LoadShader(ShaderType::Tris_Vert, "trisVert.shader");
	LoadShader(ShaderType::Tris_Frag, "trisFrag.shader");

}

void LoadedAssets::LoadShader(ShaderType key, std::string filename)
{
	std::ifstream shaderFile(Constants::PATH_SHADER + filename);

	if(!shaderFile || !shaderFile.is_open())
	{
		return;
	}

	std::string code;
	std::string line;
	while (!shaderFile.eof())
	{
		getline(shaderFile, line);

		code.append(line + "\n");
	}

	shaderFile.clear();
	shaderFile.close();
	ShaderSources[key] = code;
}

std::string LoadedAssets::GetShader(ShaderType key)
{
	return ShaderSources[key];
}

LoadedAssets::~LoadedAssets()
{
}
