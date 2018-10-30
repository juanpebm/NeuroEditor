/*
 * Copyright (c) 2018 CCS/UPM - GMRV/URJC.
 *
 * Authors: Juan Pedro Brito Méndez <juanpedro.brito@upm.es>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef RETRACER_H
#define RETRACER_H

#include <QMainWindow>
#include "ui_ReTracer.h"
#include "batchbuilder.h"
#include "viewer.h"

class ReTracer: public QMainWindow
{
  Q_OBJECT

    SIMP_METHOD _simplificationMode;
    ENHANCE_METHOD _enhanceMode;

    QString _inputFilePath;
    QString _ouputFilePath;

    std::vector < QString > _filesContainer;
    std::map < std::string, float > _params;

    BatchBuilder* _batchBuilder;

  public:

  Viewer* viewer;

    ReTracer ( QWidget* parent = 0 );

    ~ReTracer ( );

  private:

    Ui::ReTracerClass ui;

  private Q_SLOTS://slots:
    //Main
    void importMorphology ( );
    void exportMorphology ( );
    void setModificationInterval ( );
    void saveState ( );
    void setAutoSaveState ( );
    void undoState ( );

    //Simplification
    void setSimplificationMethod ( );
    void simplify ( int objectId_ = -1, OBJECT_TYPE objectType =
    OBJECT_TYPE::NEURITE );

    //Enhancement
    void setEnhanceMethod ( );
    void enhance ( int objectId_ = -1, OBJECT_TYPE objectType =
    OBJECT_TYPE::NEURITE );

    //Repair
    void insertNode ( );
    void deleteNode ( );
    void insertEdge ( );
    void deleteEdge ( );
    void interpolateRadius ( );
    void middlePosition ( );
    void setRadiusToSelectedNode ( );
    void brokeLink ( );
    void setLink ( );

    //Fine Selection
    void attachMorphology ( );
    void selectNeuronObject ( );
    void simplifyNeuronObject ( );
    void enhanceNeuronObject ( );

    void extractNeurite ( );
    void removeNeurite ( );
    void setTreeModel ( );

    //Utils
    void showBatchBuilder ( );
    bool copyRecursively ( const QString& sourceFolder,
                           const QString& destFolder );
    void genetareNeuronsInBatch ( );

    //Render
    void setRenderModifiedMorphology ( );
    void setRenderOriginalMorphology ( );
    void setMorphologyToShowInfo ( );
    void showTextValues ( );
    void changeToDualView ( );
    void colorToButtons ( );

    void setResolutionToNodes ( );
    void setNodeIncToMorphology ( );

    void setNodeColorToOriginalMorphology ( );
    void setNodeColorToModifiedMorphology ( );
    void setLinkColorToOriginalMorphology ( );
    void setLinkColorToModifiedMorphology ( );

    //Others
    void setModifiedAsOriginal ( );
    void testPythonIntegration ( );

    void quit();
    void takeSnapshot();
    void help();
};

#endif // RETRACER_H
