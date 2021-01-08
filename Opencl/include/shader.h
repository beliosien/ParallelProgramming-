
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <stdio.h>  
#include <malloc.h> 
#include <unordered_map>


struct shaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};


class shader 
{
private:
    std::string m_FilePath;
    unsigned int m_rendererID;
    std::unordered_map<std::string, int> m_uniformLocationCache;
public:
    shader(const std::string& filepath);
    ~shader();


    void Bind() const;
    void Unbind() const;

    void SetUniform1f(const std::string& name, float value);
    void SetUniform4f(const std::string& name, float v0, float v1, float f1, float f2);
private:
    unsigned int CompileShader(unsigned int type,const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    shaderProgramSource ParseShader(const std::string& filePath);

    int GetUniformLocation(const std::string& name);
};