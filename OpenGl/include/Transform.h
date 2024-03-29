#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
private:
    glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;
    
public:
    
    Transform(const glm::vec3& pos= glm::vec3(), 
        const glm::vec3& rot= glm::vec3(), 
        const glm::vec3& scale= glm::vec3(1.0f, 1.0f, 1.0f))
    {
        this->m_pos = pos;
        this->m_rot = rot;  
        this->m_scale = scale;
    }

    inline glm::mat4 getModel() const
    {
        glm::mat4 posMatrix = glm::translate(m_pos);
        glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1.0, 0.0, 0.0));
        glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0.0, 0.0, 1.0));
        glm::mat4 scaleMatrix = glm::scale(m_scale);

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::vec3& getPos() { return this->m_pos; }
    inline glm::vec3& getRot() { return this->m_rot; }
    inline glm::vec3& getScale() { return this->m_scale; }

    inline void setPos(const glm::vec3& pos) { this->m_pos = pos; }
    inline void setRot(const glm::vec3& rot) { this->m_rot = rot; }
    inline void setScale(const glm::vec3& scale) { this->m_scale = scale; } 
};


#endif // TRANSFORM_H

