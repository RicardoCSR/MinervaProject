const uint8_t Lato_Regular_10Bitmaps[] PROGMEM = {

	0x70,0x92,0x24,0x28,0x89,0x1C,0x00, // '0'
	0x65,0x08,0x42,0x13,0xC0, // '1'
	0x71,0x20,0x82,0x10,0x8F,0x80, // '2'
	0x79,0x20,0x84,0x0A,0x27,0x00, // '3'
	0x10,0x51,0x22,0x4F,0xC1,0x02,0x00, // '4'
	0xF4,0x38,0x21,0x0B,0x80, // '5'
	0x32,0x39,0x29,0x4B,0x80, // '6'
	0xF0,0x88,0x44,0x22,0x00, // '7'
	0x71,0x24,0x8C,0x4B,0x27,0x80, // '8'
	0xE4,0xA5,0xE2,0x33,0x00, // '9'

};
const GFXglyph Lato_Regular_10Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {    58,   7,   7,   7,    0,   -7 }, // '0'
	  {    65,   5,   7,   7,    1,   -7 }, // '1'
	  {    70,   6,   7,   7,    0,   -7 }, // '2'
	  {    76,   6,   7,   7,    0,   -7 }, // '3'
	  {    82,   7,   7,   7,    0,   -7 }, // '4'
	  {    89,   5,   7,   7,    1,   -7 }, // '5'
	  {    94,   5,   7,   7,    1,   -7 }, // '6'
	  {    99,   5,   7,   7,    1,   -7 }, // '7'
	  {   104,   6,   7,   7,    0,   -7 }, // '8'
	  {   110,   5,   7,   7,    1,   -7 }, // '9'

};
const GFXfont Lato_Regular_10 PROGMEM = {
(uint8_t  *)Lato_Regular_10Bitmaps,(GFXglyph *)Lato_Regular_10Glyphs,0x20, 0x7E, 13};