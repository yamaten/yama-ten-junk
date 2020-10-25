/*** 
 * file: m48_obj.h
 * date: 2020.10.24
 *
 *
 *
 */

class M48OBJ : object {

 public:
  enum ITEM_TYPE
  {
        EMPTY = 0,
        STATIC_TEXT,     // name, text-value

	SYSTEM_VALUE,    //
	// SYSTEM_DATE_TIME,
	// SYSTEM_HOST_NAME,
		  
	USER_VALUE,    // name, 
	// USER_ID
	// USER_NME
	// USER_ADDR
	// USER_PHONE
	// USER_URL
	// USER_EMALE
	// etc.

	TICKET_VALUE,
	// TICKET_NAME,
	// TICKET_CODE,
	// TICKET_PRICE,
	// SEQ_NUMBER,
	// etc.
		  
	AUTO_COUNTER,    // name, start, step (,repeat),  end 
  };
  
  public:
  string item_name;
  int    item_order;
  Point  item_position;      // (x, y) mm
  Sizef  item_size;          // (w, h) mm
  int    item_dir;           // 0,90,180,270 deg.
  Size   item_magnification; // (w-mag, h-mag)
  int    h_aline;            // 0:left, 1:center, 2:right
  int    v_aline;            // 0:top, 1:middle, 2:bottom
   
  enum   ITEM_TYPE    ItemType;
  enum   ITEM_SUBTYPE ItemSubtype;
  
  private:
  Font   font;

  public:
  string font_name;          // 'MS-Gothic.. etc'
  float  font_size;          // points
  string font_style;         // bold, itlic, etc
  int    font_dir;           // 0, 90, 180, 270 deg.

  public:
  string barcode_name;       // 'NW7', 'CODE39', 'JAN8', 'JAN13', 'QR', etc.   
  bool   bar_humanreadable;  
  bool   bar_checkdigit;
  char   bar_start_char;
  char   bar_stop_char;
  Sizef  bar_size;
  int    bar_h_maginificaion;
    
  public:
  M48OBJ() { init(); }
  void   init();
  void   draw();

  M48OBJ* new_item(enum ITEM_TYPE, ITEM_SUBTYPE);
  string chg_name(string name);
  Size   chg_size();
  Point  chg_position();
  int    chg_direction;
  int    chg_magnification();
  int    chg_valine();
  int    chg_haline();
  Font*  chg_font();

  public:
  void   on_item_add();
  void   on_item_delete();

  pulic:
  void   on_item_copy();
  void   on_item_cut();
  void   on_item_paste();

  protected:
  void   on_key_down();
  void   on_mouse_click();
  void   on_mouse_drag();
  void   on_item_move();
  void   on_item_resize();
  void   on_item_draw()
};

