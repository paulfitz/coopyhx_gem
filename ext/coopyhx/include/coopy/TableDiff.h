#ifndef INCLUDED_coopy_TableDiff
#define INCLUDED_coopy_TableDiff

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Alignment)
HX_DECLARE_CLASS1(coopy,CompareFlags)
HX_DECLARE_CLASS1(coopy,Datum)
HX_DECLARE_CLASS1(coopy,Report)
HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,TableDiff)
HX_DECLARE_CLASS1(coopy,View)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  TableDiff_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TableDiff_obj OBJ_;
		TableDiff_obj();
		Void __construct(::coopy::Alignment align,::coopy::CompareFlags flags);

	public:
		static hx::ObjectPtr< TableDiff_obj > __new(::coopy::Alignment align,::coopy::CompareFlags flags);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TableDiff_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TableDiff"); }

		virtual ::coopy::Report test( );
		Dynamic test_dyn();

		virtual bool hilite( ::coopy::Table output);
		Dynamic hilite_dyn();

		virtual ::String quoteForDiff( ::coopy::View v,::coopy::Datum d);
		Dynamic quoteForDiff_dyn();

		virtual ::String getSeparator( ::coopy::Table t,::coopy::Table t2,::String root);
		Dynamic getSeparator_dyn();

		::coopy::CompareFlags flags;
		::coopy::Alignment align;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_TableDiff */ 
