#ifndef INCLUDED_coopy_DiffRender
#define INCLUDED_coopy_DiffRender

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,DiffRender)
HX_DECLARE_CLASS1(coopy,Table)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  DiffRender_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DiffRender_obj OBJ_;
		DiffRender_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DiffRender_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DiffRender_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DiffRender"); }

		virtual Void render( ::coopy::Table rows);
		Dynamic render_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String html( );
		Dynamic html_dyn();

		virtual Void endTable( );
		Dynamic endTable_dyn();

		virtual Void endRow( );
		Dynamic endRow_dyn();

		virtual Void insertCell( ::String txt,::String mode,::String separator);
		Dynamic insertCell_dyn();

		virtual Void beginRow( ::String mode);
		Dynamic beginRow_dyn();

		virtual Void beginTable( );
		Dynamic beginTable_dyn();

		virtual Void insert( ::String str);
		Dynamic insert_dyn();

		bool open;
		::String row_color;
		::String td_close;
		::String td_open;
		Array< ::String > text_to_insert;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_DiffRender */ 
