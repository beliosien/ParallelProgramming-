#include "renderer.h"

void renderer::Draw(const vertexArray& va, const indexBuffer& ib, const shader& shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();
    glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}