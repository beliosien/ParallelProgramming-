#pragma once

#include "indexBuffer.h"
#include "shader.h"
#include "vertexArray.h"

class renderer {
   private:
   public:
    void Draw(const vertexArray& va, const indexBuffer& ib, const shader& shader) const;
};