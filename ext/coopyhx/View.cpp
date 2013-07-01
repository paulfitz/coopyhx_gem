#include <hxcpp.h>

#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
namespace coopy{

HX_DEFINE_DYNAMIC_FUNC1(View_obj,toDatum,return )

HX_DEFINE_DYNAMIC_FUNC2(View_obj,equals,return )

HX_DEFINE_DYNAMIC_FUNC1(View_obj,hasStructure,return )

HX_DEFINE_DYNAMIC_FUNC1(View_obj,getTable,return )

HX_DEFINE_DYNAMIC_FUNC1(View_obj,getBag,return )

HX_DEFINE_DYNAMIC_FUNC1(View_obj,toString,return )


static ::String sMemberFields[] = {
	HX_CSTRING("toDatum"),
	HX_CSTRING("equals"),
	HX_CSTRING("hasStructure"),
	HX_CSTRING("getTable"),
	HX_CSTRING("getBag"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(View_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(View_obj::__mClass,"__mClass");
};

Class View_obj::__mClass;

void View_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.View"), hx::TCanCast< View_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void View_obj::__boot()
{
}

} // end namespace coopy
