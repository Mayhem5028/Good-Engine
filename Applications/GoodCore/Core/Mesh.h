#pragma once

#include "IRenderable.h"
#include "ISceneNode.h"

#include "Vertex.h"
#include "Material.h"

#include <GL\glew.h>

#include <vector>
#include <memory>

namespace Good
{
	class GOOD_DLL Mesh : public ISceneNode, public IRenderable
	{
	public:
		Mesh(const std::string& name, const ISceneNodePtr& parent);
		~Mesh();

		virtual bool init();
		virtual float draw();
		virtual bool shutdown();
#pragma endregion

		VerticesList vertices() const;
		unsigned int addVertex(Vertex& vertex);
		unsigned int addVertex(const glm::vec3& postion);

		void createTriangles(unsigned int tri1, unsigned int tri2, unsigned int tri3);
		void createTriangles(const Vertex& v1, const Vertex& v2, const Vertex& v3);

		void setMaterial(MaterialPtr material);

	private:
		void _createVertexBufferData();
		void _createIndicesBufferData();
		void _orienteTriangles();
		void _computeNormals();

		VerticesList::const_iterator _findVertex(const Vertex& vertex);

		std::vector<unsigned int> _indices;
		VerticesList _vertices;
		EdgesList _edges;
		TrianglesList _triangles;

		GLuint _vaoID;
		GLuint _vertexBufferID;
		GLuint _indicesBufferID;

		bool _isIndiced;

		MaterialPtr _material;
	};

	typedef std::shared_ptr<Mesh> MeshPtr;
}
