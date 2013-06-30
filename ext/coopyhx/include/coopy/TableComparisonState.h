#ifndef INCLUDED_coopy_TableComparisonState
#define INCLUDED_coopy_TableComparisonState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,TableComparisonState)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  TableComparisonState_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TableComparisonState_obj OBJ_;
		TableComparisonState_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TableComparisonState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TableComparisonState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TableComparisonState"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		bool has_same_columns_known;
		bool has_same_columns;
		bool is_equal_known;
		bool is_equal;
		bool run_to_completion;
		bool completed;
		::coopy::Table b;
		::coopy::Table a;
		::coopy::Table p;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_TableComparisonState */ 
