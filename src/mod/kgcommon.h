/* ////////// LICENSE INFO ////////////////////

 * Copyright (C) 2013 by NYSOL CORPORATION
 *
 * Unless you have received this program directly from NYSOL pursuant
 * to the terms of a commercial license agreement with NYSOL, then
 * this program is licensed to you under the terms of the GNU Affero General
 * Public License (AGPL) as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF 
 * NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Please refer to the AGPL (http://www.gnu.org/licenses/agpl-3.0.txt)
 * for more details.

 ////////// LICENSE INFO ////////////////////*/
// =============================================================================
// kgcommon.h 参照ファイルによる行選択クラス
// =============================================================================
#pragma once
#include <kgmod.h>
#include <kgmodincludesort.h>
#include <kgArgFld.h>
#include <kgCSV.h>
#include <kgCSVout.h>

using namespace kglib;

namespace kgmod { ////////////////////////////////////////////// start namespace

class kgCommon:public  kgModIncludeSort {

	// 引数
	kgArgFld _kField;  // k=
	kgArgFld _KField;  // K=
	kgCSVfld _iFile;   // i=
	kgCSVfld _mFile;   // m=
	kgCSVout _oFile;   // o=
	kgCSVout _uFile;   // u=
	bool     _reverse; // -r
	bool     _elsefile; // 不一致ファイルを使用するかどうか(u=の指定があればtrue)
	// 引数セット
	void setArgs(void);
public:

	// コンストラクタ
	kgCommon(void);
	~kgCommon(void){}

	//実行メソッド
	int run(void);

	// 処理行数取得メソッド
	size_t iRecNo(void) const { return _iFile.recNo(); }
	size_t mRecNo(void) const { return _mFile.recNo(); }
	size_t oRecNo(void) const { return _oFile.recNo(); }

};

}
