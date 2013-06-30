#include <hxcpp.h>

#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
namespace coopy{

HX_DEFINE_DYNAMIC_FUNC0(Bag_obj,getItemView,return )

HX_DEFINE_DYNAMIC_FUNC1(Bag_obj,getItem,return )


static ::String sMemberFields[] = {
	HX_CSTRING("getItemView"),
	HX_CSTRING("getItem"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bag_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bag_obj::__mClass,"__mClass");
};

Class Bag_obj::__mClass;

void Bag_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Bag"), hx::TCanCast< Bag_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bag_obj::__boot()
{
}

} // end namespace coopy
