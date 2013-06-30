#ifndef INCLUDED_coopy_Report
#define INCLUDED_coopy_Report

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Change)
HX_DECLARE_CLASS1(coopy,Report)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  Report_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Report_obj OBJ_;
		Report_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Report_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Report_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Report"); }

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		Array< ::coopy::Change > changes;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_Report */ 