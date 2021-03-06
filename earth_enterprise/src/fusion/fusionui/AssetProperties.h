/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _AssetProperties_h_
#define _AssetProperties_h_

#include <qlistview.h>
#include <autoingest/AssetVersion.h>
#include "SystemListener.h"
#include "assetpropertiesbase.h"

#include <gstAssetGroup.h>

class AssetVersionItem : public QListViewItem, public AssetWatcher
{
 public:
  AssetVersionItem( QListView *parent, const AssetVersion & );

  std::string getVersionRef() const { return ref; }

  int compare( QListViewItem *item, int, bool ) const;

  void paintCell( QPainter *, const QColorGroup &cg, int column, int width, int alignment );

  virtual void changed(void);
};

// ------------------------------------------------------------------------

class AssetProperties : public AssetPropertiesBase
{
  Q_OBJECT

 public:
  AssetProperties( QWidget *, const gstAssetHandle & );
  ~AssetProperties();

  void refresh();

 protected:
  void selectVersion( QListViewItem * );

 private:
  const gstAssetHandle assetHandle;

public slots:
void rmbClicked( QListViewItem *item, const QPoint &pos, int );
};

#endif // !_AssetProperties_h_
