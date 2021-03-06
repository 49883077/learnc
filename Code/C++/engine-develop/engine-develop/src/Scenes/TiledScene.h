#pragma once

#include "BaseScene.h"
#include <map>
#include <functional>

namespace star
{
	class XMLContainer;
	class SpriteComponent;

	class TiledScene : public BaseScene
	{
	public:
		struct TileSet
		{
			uint32 firstGid, tileWidth, tileHeight, width, height;
			tstring texture, name;
		};

		struct TileObject
		{
			tstring type, name;
			int32 id, x, y;
			uint32 width, height;

			TileObject();
		};

		TiledScene(const tstring & name, float32 scale = 1.0f);
		virtual ~TiledScene();

		virtual void RemoveObject(Object * object);
	protected:

		virtual void CreateObjects();
		virtual void AfterInitializedObjects();
		virtual void OnActivate();
		virtual void OnDeactivate();
		virtual void Update(const Context& context);
		virtual void Draw();

		void CreateLevel(const tstring & file,
			DirectoryMode mode = DEFAULT_DIRECTORY_MODE);
		void CreateLevel(const tstring & file, const tstring & binary_file,
			DirectoryMode mode = DEFAULT_DIRECTORY_MODE);
		void BaseCreateLevel(XMLContainer & container);

		void ClearLevel();

		void DefineSpecialObject(const tstring & object_id,
			const std::function<Object*(const TileObject&)> & func);

		void ExtendTile(uint32 tileID,
			const std::function<void(Object*)> & func);

		void ExtendTiles(uint32 * tileIDArray, uint32 size,
			const std::function<void(Object*)> & func);

		void GetCorrectTileset(uint32 gid, TileSet & set) const;
		star::SpriteComponent * CreateSpriteFromGid(uint32 gid, const TileSet & set);
		tstring GetSpritesheetName(const TileSet & set) const;

		uint32 m_Width, m_Height, m_TileWidth, m_TileHeight;
		float32 m_Scale;
		std::vector<TileSet> m_TileSets;
		std::vector<Object*> m_TiledObjects;
		std::map<tstring, std::function<Object*(const TileObject&)>> m_DefinedObject;
		std::map<uint32, std::function<void(Object*)>> m_ExtensionTiles;

	private:
		void CreateTiledObjects(XMLContainer & container);
		void CreateGroupedObjects(XMLContainer & container);

		TiledScene(const TiledScene& t);
		TiledScene(TiledScene&& t);
		TiledScene& operator=(const TiledScene& t);
		TiledScene& operator=(TiledScene&& t);
	};
}
