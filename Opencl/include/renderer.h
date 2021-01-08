#pragma once

#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"



class renderer
{
private:

public:
    void Draw(const vertexArray& va, const indexBuffer& ib, const shader& shader) const;
}