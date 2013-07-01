#include <hxcpp.h>

#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
namespace coopy{

HX_DEFINE_DYNAMIC_FUNC0(Table_obj,trimBlank,return )

HX_DEFINE_DYNAMIC_FUNC2(Table_obj,insertOrDeleteColumns,return )

HX_DEFINE_DYNAMIC_FUNC2(Table_obj,insertOrDeleteRows,return )

HX_DEFINE_DYNAMIC_FUNC0(Table_obj,clear,)

HX_DEFINE_DYNAMIC_FUNC2(Table_obj,resize,return )

HX_DEFINE_DYNAMIC_FUNC0(Table_obj,isResizable,return )

HX_DEFINE_DYNAMIC_FUNC0(Table_obj,getCellView,return )

HX_DEFINE_DYNAMIC_FUNC3(Table_obj,setCell,)

HX_DEFINE_DYNAMIC_FUNC2(Table_obj,getCell,return )


static ::String sMemberFields[] = {
	HX_CSTRING("trimBlank"),
	HX_CSTRING("insertOrDeleteColumns"),
	HX_CSTRING("insertOrDeleteRows"),
	HX_CSTRING("clear"),
	HX_CSTRING("resize"),
	HX_CSTRING("isResizable"),
	HX_CSTRING("getCellView"),
	HX_CSTRING("setCell"),
	HX_CSTRING("getCell"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Table_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Table_obj::__mClass,"__mClass");
};

Class Table_obj::__mClass;

void Table_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Table"), hx::TCanCast< Table_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Table_obj::__boot()
{
}

} // end namespace coopy
