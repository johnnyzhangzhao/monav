/*
Copyright 2010  Christian Vetter veaac.fdirct@gmail.com

This file is part of MoNav.

MoNav is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MoNav is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MoNav.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAPNIKRENDERER_H
#define MAPNIKRENDERER_H

#include <QDataStream>
#include <QFile>
#include "rendererbase.h"

class MapnikRendererClient : public RendererBase
{
	Q_OBJECT

public:

	MapnikRendererClient();
	virtual ~MapnikRendererClient();
	virtual QString GetName();
	virtual int GetMaxZoom();

protected:

	virtual bool loadTile( int x, int y, int zoom, QPixmap** tile );
	virtual bool load();
	virtual void unload();

	struct Box
	{
		int minX;
		int maxX;
		int minY;
		int maxY;
	};

	int maxZoom;
	QVector< Box > boxes;
	QFile* indexFile;
	QFile* tileFile;
	int fileZoom;
};

#endif // MAPNIKRENDERER_H