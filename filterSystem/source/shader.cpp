#include "shader.h"


shader::shader(const std::string& filepath) : m_FilePath(filepath), m_rendererID(0) {
    shaderProgramSource source = ParseShader(filepath);
    m_rendererID               = CreateShader(source.VertexSource, source.FragmentSource);
}

shader::~shader() {
    glDeleteProgram(m_rendererID);
}

unsigned int shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    int InfoLogLength;

    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(id, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << "shader!" << std::endl;
        glDeleteShader(id);
        return 0;
	}

    return id;
}

shaderProgramSource shader::ParseShader(const std::string& filePath) {
    std::ifstream stream;
    stream.open(filePath, std::ios::in);

    enum class shaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

    std::string line;
    std::stringstream ss[2];
    shaderType type = shaderType::NONE;

    if (stream.is_open())
    {
        while (getline(stream, line)) 
        {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) {
                    type = shaderType::VERTEX;
                } else if (line.find("fragment") != std::string::npos) {
                    type = shaderType::FRAGMENT;
                }
            } else {
                ss[(int)type] << line << "\n";
            }
        }
    }

    return {ss[0].str(), ss[1].str()};
}

unsigned int shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs      = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs      = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void shader::Bind() const {
    glUseProgram(m_rendererID);
}

void shader::Unbind() const {
    glUseProgram(0);
}

void shader::SetUniform1i(const std::string& name, int value){
    glUniform1i(GetUniformLocation(name), value);
}

void shader::SetUniform1f(const std::string& name, float value) {
    glUniform1f(GetUniformLocation(name), value);
}

void shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
    glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

int shader::GetUniformLocation(const std::string& name) {
    if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end()) {
        return m_uniformLocationCache[name];
    }

    int location = glGetUniformLocation(m_rendererID, name.c_str());
    if (location == -1)
        std::cout << "warning: uniform ' " << name << " ' doesn't exist!" << std::endl;

    m_uniformLocationCache[name] = location;
    return location;
}