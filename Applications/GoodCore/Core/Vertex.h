#pragma once

#include "GoodFoundation.h"
#include "IRenderable.h"

#include <memory>
#include <vector>

namespace Good{
	struct Triangle;
	typedef std::shared_ptr<Triangle> TrianglePtr;
	typedef std::vector<TrianglePtr> TrianglesList;

	struct GOOD_DLL Vertex
	{
		Vertex(void);
		~Vertex(void);

		Vertex(const Vertex& vertex);
		Vertex(const Vertex&& vertex);

		glm::vec3 position;
		glm::vec3 color;
		glm::vec3 normal;
		glm::vec2 uv;

		unsigned int indice;

		TrianglesList triangles;

		bool operator==(const Vertex& vertex) const;
		bool operator!=(const Vertex& vertex) const;

		Vertex& operator=(const Vertex& vertex);
		Vertex& operator=(const Vertex&& vertex);

		/*
		glm::vec3 secondaryColor;
		glm::vec3 fogCoord;
		GLBool edgeFlag;*/

	private:
		void _randomColor();
	};

	typedef std::shared_ptr<Vertex> VertexPtr;
	typedef std::vector<Vertex> VerticesList;

	struct Edge
	{
		VertexPtr v1;
		VertexPtr v2;
	};

	typedef std::shared_ptr<Edge> EdgePtr;
	typedef std::vector<EdgePtr> EdgesList;

	struct Triangle
	{
		Vertex* v1;
		Vertex* v2;
		Vertex* v3;

		glm::vec3 normal;
		glm::vec3 tangente;
	};
}

