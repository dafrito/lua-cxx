#include "QFrame.hpp"
#include "../convert/callable.hpp"
#include "../thread.hpp"

#include "QWidget.hpp"
#include "../Qt5Core/QRect.hpp"

void lua::QFrame_metatable(lua_State* const state, const int pos)
{
    lua::QWidget_metatable(state, pos);

    lua::index mt(state, pos);
    mt["frameRect"] = &QFrame::frameRect;
    mt["frameShadow"] = &QFrame::frameShadow;
    mt["frameShape"] = &QFrame::frameShape;
    mt["frameStyle"] = &QFrame::frameStyle;
    mt["frameWidth"] = &QFrame::frameWidth;
    mt["lineWidth"] = &QFrame::lineWidth;
    mt["midLineWidth"] = &QFrame::midLineWidth;
    mt["setFrameRect"] = &QFrame::setFrameRect;
    mt["setFrameShadow"] = &QFrame::setFrameShadow;
    mt["setFrameShape"] = &QFrame::setFrameShape;
    mt["setFrameStyle"] = &QFrame::setFrameStyle;
    mt["setLineWidth"] = &QFrame::setLineWidth;
    mt["setMidLineWidth"] = &QFrame::setMidLineWidth;
}

int QFrame_new(lua_State* const state)
{
    // QFrame(QWidget * parent = 0, Qt::WindowFlags f = 0)
    lua::make<QFrame>(state);
    // TODO Set up object-specific methods

    return 1;
}

int luaopen_Qt5Widgets_QFrame(lua_State* const state)
{
    lua::thread env(state);

    env["QFrame"] = lua::value::table;
    env["QFrame"]["new"] = QFrame_new;
    auto t = env["QFrame"];

    // enum QFrame::Shadow
    t["Plain"] = QFrame::Plain;
    t["Raised"] = QFrame::Raised;
    t["Sunken"] = QFrame::Sunken;

    // enum QFrame::Shape
    t["NoFrame"] = QFrame::NoFrame;
    t["Box"] = QFrame::Box;
    t["Panel"] = QFrame::Panel;
    t["StyledPanel"] = QFrame::StyledPanel;
    t["HLine"] = QFrame::HLine;
    t["VLine"] = QFrame::VLine;
    t["WinPanel"] = QFrame::WinPanel;

    // enum QFrame::StyleMask
    t["Shadow_Mask"] = QFrame::Shadow_Mask;
    t["Shape_Mask"] = QFrame::Shape_Mask;

    return 0;
}
