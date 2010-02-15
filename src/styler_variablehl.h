/*******************************************************************************
 *
 * Copyright (C) 2009, Alexander Stigsen, e-texteditor.com
 *
 * This software is licensed under the Open Company License as described
 * in the file license.txt, which you should have received as part of this
 * distribution. The terms are also available at http://opencompany.org/license.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ******************************************************************************/

#ifndef __STYLER_VARIABLEHL_H__
#define __STYLER_VARIABLEHL_H__

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include <wx/string.h>
	#include <wx/colour.h>
#endif

#include "Catalyst.h"
#include "styler.h"
#include "styler_searchhl.h"
#include "eSettings.h"

#include <vector>


class DocumentWrapper;
class StyleRun;
struct tmTheme;
class Lines;

class Styler_VariableHL : public Styler_SearchHL {
public:
	Styler_VariableHL(const DocumentWrapper& rev, const Lines& lines, const std::vector<interval>& ranges, const tmTheme& theme, eSettings& settings);
	virtual ~Styler_VariableHL() {};

	void Clear();

	void SetCurrentWord(const wxString& text, bool click, unsigned int cursosPosition, int key);
	void Style(StyleRun& sr);

	bool ShouldStyle();
	bool IsCurrentWord(unsigned int start, unsigned int end);

	// Handle document changes
	void Insert(unsigned int pos, unsigned int length);
	void Delete(unsigned int start_pos, unsigned int end_pos);
	
	void ApplyStyle(StyleRun& sr, unsigned int start, unsigned int pos);
	bool FilterMatch(search_result& result, const Document& doc);

private:
	eSettings& m_settings;

	bool m_click;
	unsigned int m_cursorPosition;
	int m_key;

	const wxColour& m_searchHighlightColor;
	const wxColour& m_selectionHighlightColor;
};

#endif // __STYLER_VARIABLEHL_H__
