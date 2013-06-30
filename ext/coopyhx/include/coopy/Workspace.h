#ifndef INCLUDED_coopy_Workspace
#define INCLUDED_coopy_Workspace

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Report)
HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,TableComparisonState)
HX_DECLARE_CLASS1(coopy,ViewedDatum)
HX_DECLARE_CLASS1(coopy,Workspace)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  Workspace_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Workspace_obj OBJ_;
		Workspace_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Workspace_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Workspace_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Workspace"); }

		::coopy::TableComparisonState l2r;
		::coopy::TableComparisonState p2r;
		::coopy::TableComparisonState p2l;
		::coopy::Table tremote;
		::coopy::Table tlocal;
		::coopy::Table tparent;
		::coopy::Report report;
		::coopy::ViewedDatum remote;
		::coopy::ViewedDatum local;
		::coopy::ViewedDatum parent;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_Workspace */ 
