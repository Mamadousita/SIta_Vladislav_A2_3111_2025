#include "GeometryGenerator.h"
#include <algorithm>
#include <cmath>
using namespace DirectX;

GeometryGenerator::MeshData
GeometryGenerator::CreateBox(float width, float height, float depth, uint32 numSubdivisions)
{
    MeshData meshData;

    //
    // Create the vertices of the box.
    //
    Vertex v[24];

    float w2 = 0.5f * width;
    float h2 = 0.5f * height;
    float d2 = 0.5f * depth;

    // Fill in the front face.
    v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    // Back face.
    v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Top face.
    v[8] = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    v[9] = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    // Bottom face.
    v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Left face.
    v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
    v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
    v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
    v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

    // Right face.
    v[20] = Vertex(+w2, -h2, -d2, +1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    v[21] = Vertex(+w2, +h2, -d2, +1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    v[22] = Vertex(+w2, +h2, +d2, +1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
    v[23] = Vertex(+w2, -h2, +d2, +1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

    meshData.Vertices.assign(&v[0], &v[24]);

    //
    // Create the indices.
    //
    uint32 i[36];
    // Front face
    i[0] = 0; i[1] = 1; i[2] = 2;
    i[3] = 0; i[4] = 2; i[5] = 3;
    // Back face
    i[6] = 4; i[7] = 5; i[8] = 6;
    i[9] = 4; i[10] = 6; i[11] = 7;
    // Top face
    i[12] = 8; i[13] = 9; i[14] = 10;
    i[15] = 8; i[16] = 10; i[17] = 11;
    // Bottom face
    i[18] = 12; i[19] = 13; i[20] = 14;
    i[21] = 12; i[22] = 14; i[23] = 15;
    // Left face
    i[24] = 16; i[25] = 17; i[26] = 18;
    i[27] = 16; i[28] = 18; i[29] = 19;
    // Right face
    i[30] = 20; i[31] = 21; i[32] = 22;
    i[33] = 20; i[34] = 22; i[35] = 23;

    meshData.Indices32.assign(&i[0], &i[36]);

    // Limit the number of subdivisions.
    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);
    for (uint32 j = 0; j < numSubdivisions; ++j)
        Subdivide(meshData);

    return meshData;
}

GeometryGenerator::MeshData
GeometryGenerator::CreateSphere(float radius, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

    //
    // Build sphere from top pole down.
    //
    Vertex topVertex(0.0f, +radius, 0.0f,
        0.0f, +1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f);
    Vertex bottomVertex(0.0f, -radius, 0.0f,
        0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f);

    meshData.Vertices.push_back(topVertex);

    float phiStep = XM_PI / stackCount;
    float thetaStep = 2.0f * XM_PI / sliceCount;

    // Compute vertices for each stack ring (not counting poles).
    for (uint32 i = 1; i <= stackCount - 1; ++i)
    {
        float phi = i * phiStep;
        for (uint32 j = 0; j <= sliceCount; ++j)
        {
            float theta = j * thetaStep;
            Vertex v;

            // spherical to cartesian
            v.Position.x = radius * sinf(phi) * cosf(theta);
            v.Position.y = radius * cosf(phi);
            v.Position.z = radius * sinf(phi) * sinf(theta);

            // Partial derivative wrt theta for tangent
            v.TangentU.x = -radius * sinf(phi) * sinf(theta);
            v.TangentU.y = 0.0f;
            v.TangentU.z = radius * sinf(phi) * cosf(theta);
            XMVECTOR T = XMLoadFloat3(&v.TangentU);
            XMStoreFloat3(&v.TangentU, XMVector3Normalize(T));

            // Normal = normalized position
            XMVECTOR p = XMLoadFloat3(&v.Position);
            XMStoreFloat3(&v.Normal, XMVector3Normalize(p));

            v.TexC.x = theta / XM_2PI;
            v.TexC.y = phi / XM_PI;

            meshData.Vertices.push_back(v);
        }
    }
    meshData.Vertices.push_back(bottomVertex);

    //
    // Indices for the top stack
    //
    for (uint32 i = 1; i <= sliceCount; ++i)
    {
        meshData.Indices32.push_back(0);
        meshData.Indices32.push_back(i + 1);
        meshData.Indices32.push_back(i);
    }

    // Indexing for inner stacks
    uint32 baseIndex = 1;
    uint32 ringVertexCount = sliceCount + 1;
    for (uint32 i = 0; i < stackCount - 2; ++i)
    {
        for (uint32 j = 0; j < sliceCount; ++j)
        {
            meshData.Indices32.push_back(baseIndex + i * ringVertexCount + j);
            meshData.Indices32.push_back(baseIndex + i * ringVertexCount + j + 1);
            meshData.Indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j);

            meshData.Indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j);
            meshData.Indices32.push_back(baseIndex + i * ringVertexCount + j + 1);
            meshData.Indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
        }
    }

    // Indices for the bottom stack
    uint32 southPoleIndex = (uint32)meshData.Vertices.size() - 1;
    baseIndex = southPoleIndex - ringVertexCount;
    for (uint32 i = 0; i < sliceCount; ++i)
    {
        meshData.Indices32.push_back(southPoleIndex);
        meshData.Indices32.push_back(baseIndex + i);
        meshData.Indices32.push_back(baseIndex + i + 1);
    }

    return meshData;
}

GeometryGenerator::MeshData
GeometryGenerator::CreateGeosphere(float radius, uint32 numSubdivisions)
{
    MeshData meshData;

    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

    // Approximate sphere by subdividing icosahedron
    const float X = 0.525731f;
    const float Z = 0.850651f;

    XMFLOAT3 pos[12] =
    {
        XMFLOAT3(-X, 0.0f, Z),   XMFLOAT3(X, 0.0f, Z),
        XMFLOAT3(-X, 0.0f, -Z),  XMFLOAT3(X, 0.0f, -Z),
        XMFLOAT3(0.0f, Z, X),    XMFLOAT3(0.0f, Z, -X),
        XMFLOAT3(0.0f, -Z, X),   XMFLOAT3(0.0f, -Z, -X),
        XMFLOAT3(Z, X, 0.0f),    XMFLOAT3(-Z, X, 0.0f),
        XMFLOAT3(Z, -X, 0.0f),   XMFLOAT3(-Z, -X, 0.0f)
    };

    uint32 k[60] =
    {
        1,4,0,   4,9,0,   4,5,9,
        8,5,4,   1,8,4,   1,10,8,
        10,3,8,  8,3,5,   3,2,5,
        3,7,2,   3,10,7,  10,6,7,
        6,11,7,  6,0,11,  6,1,0,
        10,1,6,  11,0,9,  2,11,9,
        5,2,9,   11,2,7
    };

    meshData.Vertices.resize(12);
    meshData.Indices32.assign(&k[0], &k[60]);

    for (uint32 i = 0; i < 12; ++i)
        meshData.Vertices[i].Position = pos[i];

    for (uint32 i = 0; i < numSubdivisions; ++i)
        Subdivide(meshData);

    // Project onto sphere
    for (uint32 i = 0; i < meshData.Vertices.size(); ++i)
    {
        XMVECTOR n = XMVector3Normalize(XMLoadFloat3(&meshData.Vertices[i].Position));
        XMVECTOR p = radius * n;
        XMStoreFloat3(&meshData.Vertices[i].Position, p);
        XMStoreFloat3(&meshData.Vertices[i].Normal, n);

        // Derive spherical texture coords
        float theta = atan2f(meshData.Vertices[i].Position.z, meshData.Vertices[i].Position.x);
        if (theta < 0.0f) theta += XM_2PI;
        float phi = acosf(meshData.Vertices[i].Position.y / radius);

        meshData.Vertices[i].TexC.x = theta / XM_2PI;
        meshData.Vertices[i].TexC.y = phi / XM_PI;

        // partial derivative wrt theta
        meshData.Vertices[i].TangentU.x = -radius * sinf(phi) * sinf(theta);
        meshData.Vertices[i].TangentU.y = 0.0f;
        meshData.Vertices[i].TangentU.z = radius * sinf(phi) * cosf(theta);

        XMVECTOR T = XMLoadFloat3(&meshData.Vertices[i].TangentU);
        XMStoreFloat3(&meshData.Vertices[i].TangentU, XMVector3Normalize(T));
    }

    return meshData;
}

GeometryGenerator::MeshData
GeometryGenerator::CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

    float stackHeight = height / stackCount;
    float radiusStep = (topRadius - bottomRadius) / stackCount;
    uint32 ringCount = stackCount + 1;

    // Build Stacks
    for (uint32 i = 0; i < ringCount; ++i)
    {
        float y = -0.5f * height + i * stackHeight;
        float r = bottomRadius + i * radiusStep;

        // Each ring
        float dTheta = 2.0f * XM_PI / sliceCount;
        for (uint32 j = 0; j <= sliceCount; ++j)
        {
            float c = cosf(j * dTheta);
            float s = sinf(j * dTheta);

            Vertex vertex;
            vertex.Position = XMFLOAT3(r * c, y, r * s);
            vertex.TexC.x = (float)j / sliceCount;
            vertex.TexC.y = 1.0f - (float)i / stackCount;

            // Cylinder param
            vertex.TangentU = XMFLOAT3(-s, 0.0f, c);
            float dr = bottomRadius - topRadius;
            XMFLOAT3 bitangent(dr * c, -height, dr * s);
            XMVECTOR T = XMLoadFloat3(&vertex.TangentU);
            XMVECTOR B = XMLoadFloat3(&bitangent);
            XMVECTOR N = XMVector3Normalize(XMVector3Cross(T, B));
            XMStoreFloat3(&vertex.Normal, N);

            meshData.Vertices.push_back(vertex);
        }
    }

    // Indices for each stack
    uint32 ringVertexCount = sliceCount + 1;
    for (uint32 i = 0; i < stackCount; ++i)
    {
        for (uint32 j = 0; j < sliceCount; ++j)
        {
            meshData.Indices32.push_back(i * ringVertexCount + j);
            meshData.Indices32.push_back((i + 1) * ringVertexCount + j);
            meshData.Indices32.push_back((i + 1) * ringVertexCount + j + 1);

            meshData.Indices32.push_back(i * ringVertexCount + j);
            meshData.Indices32.push_back((i + 1) * ringVertexCount + j + 1);
            meshData.Indices32.push_back(i * ringVertexCount + j + 1);
        }
    }

    // Build top cap
    BuildCylinderTopCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);
    // Build bottom cap
    BuildCylinderBottomCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateCone(float bottomRadius, float height, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

    // Base du c�ne (un cercle)
    float theta = 2.0f * XM_PI / sliceCount;
    for (uint32 i = 0; i <= sliceCount; ++i)
    {
        float x = bottomRadius * cosf(i * theta);
        float z = bottomRadius * sinf(i * theta);
        meshData.Vertices.push_back({ {x, 0.0f, z}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} });
    }

    // Sommet du c�ne
    meshData.Vertices.push_back({ {0.0f, height, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.5f} });

    // Indices pour les triangles
    uint32 centerIndex = (uint32)meshData.Vertices.size() - 1;
    for (uint32 i = 0; i < sliceCount; ++i)
    {
        meshData.Indices32.push_back(i);
        meshData.Indices32.push_back((i + 1) % sliceCount);
        meshData.Indices32.push_back(centerIndex);
    }

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreatePyramid(float baseWidth, float height)
{
    MeshData meshData;

    float halfWidth = baseWidth / 2.0f;

    // Base de la pyramide (carr�)
    meshData.Vertices.push_back({ {-halfWidth, 0.0f, -halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} });
    meshData.Vertices.push_back({ {halfWidth, 0.0f, -halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} });
    meshData.Vertices.push_back({ {halfWidth, 0.0f, halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} });
    meshData.Vertices.push_back({ {-halfWidth, 0.0f, halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} });

    // Sommet de la pyramide
    meshData.Vertices.push_back({ {0.0f, height, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.5f} });

    // Indices pour les triangles
    meshData.Indices32 = {
        0, 1, 4, // Face avant
        1, 2, 4, // Face droite
        2, 3, 4, // Face arri�re
        3, 0, 4  // Face gauche
    };

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateDiamond(float width, float height)
{
    MeshData meshData;

    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    // Sommet sup�rieur
    meshData.Vertices.push_back({ {0.0f, halfHeight, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.5f} });

    // Base du diamant (carr�)
    meshData.Vertices.push_back({ {-halfWidth, 0.0f, -halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} });
    meshData.Vertices.push_back({ {halfWidth, 0.0f, -halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} });
    meshData.Vertices.push_back({ {halfWidth, 0.0f, halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} });
    meshData.Vertices.push_back({ {-halfWidth, 0.0f, halfWidth}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} });

    // Sommet inf�rieur
    meshData.Vertices.push_back({ {0.0f, -halfHeight, 0.0f}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.5f} });

    // Indices pour les triangles
    meshData.Indices32 = {
        0, 1, 2, // Face avant sup�rieure
        0, 2, 3, // Face droite sup�rieure
        0, 3, 4, // Face arri�re sup�rieure
        0, 4, 1, // Face gauche sup�rieure
        5, 2, 1, // Face avant inf�rieure
        5, 3, 2, // Face droite inf�rieure
        5, 4, 3, // Face arri�re inf�rieure
        5, 1, 4  // Face gauche inf�rieure
    };

    return meshData;
}
void GeometryGenerator::BuildCylinderTopCap(
    float bottomRadius, float topRadius, float height,
    uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
    uint32 baseIndex = (uint32)meshData.Vertices.size();
    float y = 0.5f * height;

    // Duplicate ring vertices for top cap
    float dTheta = 2.0f * XM_PI / sliceCount;
    for (uint32 i = 0; i <= sliceCount; ++i)
    {
        float x = topRadius * cosf(i * dTheta);
        float z = topRadius * sinf(i * dTheta);

        float u = x / height + 0.5f;
        float v = z / height + 0.5f;

        meshData.Vertices.push_back(Vertex(
            x, y, z,
            0.0f, +1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            u, v));
    }

    // Cap center vertex
    meshData.Vertices.push_back(Vertex(
        0.0f, y, 0.0f,
        0.0f, +1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.5f, 0.5f));

    // Triangles
    uint32 centerIndex = (uint32)meshData.Vertices.size() - 1;
    for (uint32 i = 0; i < sliceCount; ++i)
    {
        meshData.Indices32.push_back(centerIndex);
        meshData.Indices32.push_back(baseIndex + i + 1);
        meshData.Indices32.push_back(baseIndex + i);
    }
}

void GeometryGenerator::BuildCylinderBottomCap(
    float bottomRadius, float topRadius, float height,
    uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
    // Bottom cap
    uint32 baseIndex = (uint32)meshData.Vertices.size();
    float y = -0.5f * height;

    float dTheta = 2.0f * XM_PI / sliceCount;
    for (uint32 i = 0; i <= sliceCount; ++i)
    {
        float x = bottomRadius * cosf(i * dTheta);
        float z = bottomRadius * sinf(i * dTheta);

        float u = x / height + 0.5f;
        float v = z / height + 0.5f;

        meshData.Vertices.push_back(Vertex(
            x, y, z,
            0.0f, -1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            u, v));
    }

    // center vertex
    meshData.Vertices.push_back(Vertex(
        0.0f, y, 0.0f,
        0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.5f, 0.5f));

    uint32 centerIndex = (uint32)meshData.Vertices.size() - 1;
    for (uint32 i = 0; i < sliceCount; ++i)
    {
        meshData.Indices32.push_back(centerIndex);
        meshData.Indices32.push_back(baseIndex + i);
        meshData.Indices32.push_back(baseIndex + i + 1);
    }
}

GeometryGenerator::MeshData
GeometryGenerator::CreateGrid(float width, float depth, uint32 m, uint32 n)
{
    MeshData meshData;

    uint32 vertexCount = m * n;
    uint32 faceCount = (m - 1) * (n - 1) * 2;

    float halfWidth = 0.5f * width;
    float halfDepth = 0.5f * depth;

    float dx = width / (n - 1);
    float dz = depth / (m - 1);

    float du = 1.0f / (n - 1);
    float dv = 1.0f / (m - 1);

    meshData.Vertices.resize(vertexCount);
    for (uint32 i = 0; i < m; ++i)
    {
        float z = halfDepth - i * dz;
        for (uint32 j = 0; j < n; ++j)
        {
            float x = -halfWidth + j * dx;

            meshData.Vertices[i * n + j].Position = XMFLOAT3(x, 0.0f, z);
            meshData.Vertices[i * n + j].Normal = XMFLOAT3(0.0f, 1.0f, 0.0f);
            meshData.Vertices[i * n + j].TangentU = XMFLOAT3(1.0f, 0.0f, 0.0f);
            meshData.Vertices[i * n + j].TexC.x = j * du;
            meshData.Vertices[i * n + j].TexC.y = i * dv;
        }
    }

    meshData.Indices32.resize(faceCount * 3);
    uint32 k = 0;
    for (uint32 i = 0; i < m - 1; ++i)
    {
        for (uint32 j = 0; j < n - 1; ++j)
        {
            meshData.Indices32[k] = i * n + j;
            meshData.Indices32[k + 1] = i * n + j + 1;
            meshData.Indices32[k + 2] = (i + 1) * n + j;

            meshData.Indices32[k + 3] = (i + 1) * n + j;
            meshData.Indices32[k + 4] = i * n + j + 1;
            meshData.Indices32[k + 5] = (i + 1) * n + j + 1;

            k += 6;
        }
    }

    return meshData;
}

GeometryGenerator::MeshData
GeometryGenerator::CreateQuad(float x, float y, float w, float h, float depth)
{
    MeshData meshData;
    meshData.Vertices.resize(4);
    meshData.Indices32.resize(6);

    // NDC space positions
    meshData.Vertices[0] = Vertex(
        x, y - h, depth,
        0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f);
    meshData.Vertices[1] = Vertex(
        x, y, depth,
        0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f);
    meshData.Vertices[2] = Vertex(
        x + w, y, depth,
        0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f);
    meshData.Vertices[3] = Vertex(
        x + w, y - h, depth,
        0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f);

    meshData.Indices32[0] = 0;
    meshData.Indices32[1] = 1;
    meshData.Indices32[2] = 2;

    meshData.Indices32[3] = 0;
    meshData.Indices32[4] = 2;
    meshData.Indices32[5] = 3;

    return meshData;
}

void GeometryGenerator::Subdivide(MeshData& meshData)
{
    // Save input geometry
    MeshData inputCopy = meshData;

    meshData.Vertices.resize(0);
    meshData.Indices32.resize(0);

    // Each triangle subdivides into 4 smaller.
    uint32 numTris = (uint32)inputCopy.Indices32.size() / 3;
    for (uint32 i = 0; i < numTris; ++i)
    {
        Vertex v0 = inputCopy.Vertices[inputCopy.Indices32[i * 3 + 0]];
        Vertex v1 = inputCopy.Vertices[inputCopy.Indices32[i * 3 + 1]];
        Vertex v2 = inputCopy.Vertices[inputCopy.Indices32[i * 3 + 2]];

        // Midpoints
        Vertex m0 = MidPoint(v0, v1);
        Vertex m1 = MidPoint(v1, v2);
        Vertex m2 = MidPoint(v0, v2);

        // Add new geometry
        meshData.Vertices.push_back(v0); // 0
        meshData.Vertices.push_back(v1); // 1
        meshData.Vertices.push_back(v2); // 2
        meshData.Vertices.push_back(m0); // 3
        meshData.Vertices.push_back(m1); // 4
        meshData.Vertices.push_back(m2); // 5

        meshData.Indices32.push_back(i * 6 + 0);
        meshData.Indices32.push_back(i * 6 + 3);
        meshData.Indices32.push_back(i * 6 + 5);

        meshData.Indices32.push_back(i * 6 + 3);
        meshData.Indices32.push_back(i * 6 + 4);
        meshData.Indices32.push_back(i * 6 + 5);

        meshData.Indices32.push_back(i * 6 + 5);
        meshData.Indices32.push_back(i * 6 + 4);
        meshData.Indices32.push_back(i * 6 + 2);

        meshData.Indices32.push_back(i * 6 + 3);
        meshData.Indices32.push_back(i * 6 + 1);
        meshData.Indices32.push_back(i * 6 + 4);
    }
}

GeometryGenerator::Vertex GeometryGenerator::MidPoint(const Vertex& v0, const Vertex& v1)
{
    XMVECTOR p0 = XMLoadFloat3(&v0.Position);
    XMVECTOR p1 = XMLoadFloat3(&v1.Position);

    XMVECTOR n0 = XMLoadFloat3(&v0.Normal);
    XMVECTOR n1 = XMLoadFloat3(&v1.Normal);

    XMVECTOR t0 = XMLoadFloat3(&v0.TangentU);
    XMVECTOR t1 = XMLoadFloat3(&v1.TangentU);

    XMVECTOR tex0 = XMLoadFloat2(&v0.TexC);
    XMVECTOR tex1 = XMLoadFloat2(&v1.TexC);

    // Midpoints of all attributes
    XMVECTOR pos = 0.5f * (p0 + p1);
    XMVECTOR normal = XMVector3Normalize(0.5f * (n0 + n1));
    XMVECTOR tangent = XMVector3Normalize(0.5f * (t0 + t1));
    XMVECTOR tex = 0.5f * (tex0 + tex1);

    Vertex v;
    XMStoreFloat3(&v.Position, pos);
    XMStoreFloat3(&v.Normal, normal);
    XMStoreFloat3(&v.TangentU, tangent);
    XMStoreFloat2(&v.TexC, tex);
    return v;
}
