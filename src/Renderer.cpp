#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Render(Mesh& mesh, Transform& transform, Material& material, Shader& shader)
{
	glm::mat4 world = glm::mat4(1.0f);

	world = glm::translate(world, transform.position);
	world = glm::rotate(world, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	world = glm::scale(world, transform.scale);

	shader.SetUniform("uWorld", world);

	shader.SetUniform("uColor", material.color);

	shader.Bind();
	mesh.SetupDraw();
	glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
	mesh.RemoveDraw();
	shader.Unbind();
}
