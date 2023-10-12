
#define DATA_SIZE 750 

char input_data[DATA_SIZE] = 
{
   10, 116, 213,  86, 144,   0,  48, 253, 192,  93,  89, 146,  33,  16, 243,  39, 149,  55, 206,  35, 
  159,  53,   1, 146, 238,  87, 228, 152, 100, 230, 177,  58, 246,   3,  28, 226,  29, 192,  76, 165, 
  109, 128,  80, 111, 168, 179, 198, 208,  81, 251, 173,  38, 224, 178,  96, 144, 121,  69, 240,  66, 
  138, 165, 145, 130,  52,  22,  71, 180, 194, 171, 155,  96, 131, 141, 168, 240,  50, 151,  20, 145, 
   68, 243,  58, 205,  86, 149, 241, 164, 231,  94,  61, 125, 233,  84, 211,  80, 239, 151, 252,  99, 
   50, 139, 246, 166, 145, 251,  89, 255, 166, 208, 168,  20,  46,  53,  28, 255, 220, 161,  16, 217, 
   73, 180,  89, 255,  36,  64, 231, 183, 227, 110,  67, 106, 147, 138, 251, 179, 195,   1,  61, 126, 
  122,  25, 128, 221, 103, 177,  56, 106, 113,  76, 184,  73, 173, 159,  81,  20,  57,  90, 240, 138, 
   73, 165,  30,  43, 157, 135, 155,  74,  99, 204,  89, 205, 116, 184,  71, 194,  94, 191,  91,  23, 
  149, 253,  16,  69, 252, 218, 103, 202,  88, 136, 132,  57, 143, 118, 232,  61, 198,  91,  65,  85, 
  199, 175, 153, 189,  36, 114,   8,  79,  32, 190, 241, 142, 239, 122, 204, 142, 141, 237, 110, 204, 
  166,  91, 244, 228,  73, 170,   5, 131,  12, 142,  22, 222,  24, 218, 113, 112, 150,  15, 157, 173, 
   97, 101,  71,   2, 207,   4, 248,  43, 209,  74,  88,  97, 115, 137, 131,  47, 247, 235,  89, 138, 
  207, 251, 226, 227, 137,  14, 242, 156, 179, 243,  91, 122, 145,  38, 228,   1,   5, 164, 145,  85, 
  170, 187, 108,  24, 111, 186,  40,  71,   0, 101,  21, 176,  63, 233,  12, 122, 111, 208, 203, 186, 
  222,  67, 124,  32, 106,  60,  94,  54, 140,  46, 132,   1, 227, 129, 174, 152,  72,  44,  67, 164, 
  127,  88,  74, 153, 229,  17,  55, 217, 187, 168, 176, 158,  64,  31, 201,  33, 142, 212,  77, 170, 
  135, 111, 139, 125,  82, 193, 242,  32,  73, 160, 211,   3,  78,   2, 202, 103, 187,  27, 245, 180, 
   93, 209, 185, 247,  75, 104, 249, 224, 167, 219, 191,  22,  23,  15,  97, 169,  27, 171,  26,  39, 
   97,  31, 167,  25, 211, 105, 215,  60,  91,   3,  37, 108,  13, 247,  35,  55, 244, 159,  87,  92, 
  136, 236, 194, 183, 133, 165, 214,  76, 151, 227,   3, 174,  44,   9,  16, 126,  31, 141,  34, 137, 
  194, 248,  95, 164, 243, 111,  10, 106,  33,  77,  28, 112, 217, 220, 111,  52,  65, 122,  69, 253, 
  104, 173, 161, 184, 102, 253, 140,  86, 193, 115, 144, 162,  43,  39,   4, 165, 186, 116, 128, 109, 
  199, 130,  11, 253, 193, 109,  20,   3,  51, 123, 218,  36,  39,  87, 194, 100,  91,  13, 241,  43, 
  236, 154,  84,  27, 127, 248, 113,  31, 132, 225, 164,  20,  70, 223, 201, 153,  29, 154, 215, 223, 
  232, 227,  70, 156,  60, 103,   8,  60, 201, 191, 144, 134,  91,  70, 205, 113, 209,  58, 192, 192, 
   71, 241,  21, 186, 117, 181, 116,  51, 182,  13, 117, 194,  10,  13,  64, 101,  96,  10, 130,  36, 
  179, 106, 220, 191, 123,  56, 189, 122, 128, 197, 181,  46,  12, 123,  95, 177, 223, 185, 242,  44, 
  254,  47, 135, 234, 184,   0, 111, 246,  59,  63, 127, 119, 178,  92,   7, 133,  89,  59,  64,  30, 
   89,  10,  64, 199, 146,  50, 200,  41, 191, 190, 128, 112, 211,  91, 211, 103,  43,  36,  41, 162, 
  172,  74,   8, 200,  51,  82,  36, 163, 218,  30,  23, 218, 101,  18,  27, 209, 219,  99,  27, 244, 
   40,   9,   1,   4, 196, 178,  52, 178,  49, 173, 147, 153,  56, 226, 134, 211,  45, 191,  61, 118, 
  179, 131, 193, 136, 181, 112,  12, 109,  21, 187, 204, 186, 228, 180, 131, 140,  95,  22, 126, 204, 
    3,  55, 159,   5,  21, 166,  26,  15, 203, 110, 236, 168, 164,  24, 225, 249, 213, 168,  61, 247, 
  118, 134,  29,  16, 143, 160, 135,  77,   2, 183, 255, 104, 231,  14,  99, 186, 104,  78,  27, 111, 
  143, 231, 240, 151, 131, 177, 104, 204,  77, 127,  51,  45, 109, 241, 157, 255,  92, 123, 133,  40, 
  175, 210,   5, 156,  47, 174,  80,   3,  27,  28,  70, 204,  99,  47,  62,   0, 124, 184,  27,  24, 
  179, 192, 230, 189, 197, 208, 165, 111,  20,  83
};

char verify_data[DATA_SIZE] = 
{
    0, 116, 116, 144,  86,  48,  48, 192, 192,  93,  93,  89,  33,  33,  39, 149,  55, 149,  55, 159, 
   53,  53,  53, 146, 146, 228, 152, 152, 152, 177, 177, 177,  58,  28,  28,  29, 192,  76, 165, 109, 
  128, 109, 111, 111, 168, 179, 198, 198, 208, 173, 173, 173, 178, 178, 144, 121, 121, 121,  69, 138, 
  138, 145, 145, 130,  52,  52,  71, 180, 180, 171, 155, 131, 131, 141, 168, 168, 151,  50, 145,  68, 
  145,  68, 205,  86, 149, 149, 164, 231, 164,  94,  94, 125, 125, 211,  84, 211, 151, 239, 151,  99, 
   99, 139, 166, 166, 166, 145, 251, 166, 208, 168, 168,  46,  46,  46,  53, 220, 220, 161, 161,  73, 
  180,  89, 180,  89,  64,  64, 183, 227, 183, 110, 106, 106, 138, 147, 179, 195, 179,  61,  61, 122, 
  122, 122, 128, 128, 177, 103, 106, 106, 106, 113,  76, 173, 159, 159,  81,  57,  57,  90, 138, 138, 
  138,  73,  43,  43, 135, 155, 135,  99,  99,  99, 204, 116, 184, 116, 184,  94, 191,  94,  91,  91, 
  149, 149,  69,  69, 218, 218, 202, 103, 136, 132, 132, 132, 118, 143, 118, 198,  91,  91,  85,  85, 
  175, 175, 175, 153, 114,  36,  79,  32,  79, 190, 190, 239, 142, 204, 142, 142, 142, 141, 204, 166, 
  166, 166, 228, 228, 170,  73, 131,  12, 131,  22, 142,  24, 218, 113, 113, 113, 112, 150, 157, 157, 
  101,  97,  71,  71,   4, 207,  43, 209,  74,  88,  88,  97, 115, 131, 131, 131, 235, 235, 138, 138, 
  207, 226, 227, 226, 137, 137, 156, 179, 179, 179, 122, 122, 122, 145,  38,   5,   5, 145, 145, 145, 
  170, 170, 108, 108, 111, 111,  71,  40,  71,  21, 101,  63, 176,  63, 122, 111, 122, 203, 203, 203, 
  186, 124,  67, 106,  60,  94,  60,  94,  54, 132,  46, 132, 129, 174, 152, 152,  72,  67,  67, 127, 
  127,  88,  88, 153, 153,  55,  55, 187, 187, 176, 168, 158,  64,  64,  33, 142, 142, 142, 170, 135, 
  135, 135, 125, 125, 125, 193, 193,  73,  73, 160, 160,  78,   3,  78, 103, 187, 103, 187, 180, 180, 
  180, 185, 209, 185, 104, 104, 224, 224, 219, 191, 191,  23,  22,  23,  97,  97, 169,  27,  39,  39, 
   39,  97,  31, 167, 105, 211, 105,  91,  60,  37,  37,  37, 108,  35,  55,  55, 159, 159,  92,  92, 
  136, 194, 194, 183, 165, 165, 165, 151, 151, 151, 174,  44,  44,  16,  16,  31, 126,  34, 137, 137, 
  194, 194, 164, 164, 164, 111, 106,  33,  77,  33,  77, 112, 217, 217, 111,  65,  65,  69, 122, 104, 
  173, 161, 173, 161, 184, 140, 140, 140, 115, 144, 144, 144,  43,  39,  39, 165, 165, 128, 116, 128, 
  130, 130, 130, 193, 193, 109,  20,  20,  51, 123, 123,  39,  39,  87, 100, 100,  91,  91,  43, 236, 
  154, 154,  84,  84, 127, 127, 113, 113, 132, 164, 164,  70,  70, 201, 201, 153, 153, 154, 215, 223, 
  227, 227, 156,  70, 103,  60,  60,  60, 191, 191, 144, 134,  91,  91, 113, 205, 113, 192, 192, 192, 
  192,  71, 186, 117, 181, 117, 116, 116,  51, 117, 117, 117,  13,  13,  64,  96,  96,  96,  36, 130, 
  106, 179, 191, 191, 123, 123, 122, 128, 128, 181, 181,  46,  46,  95, 123, 177, 185, 223, 185, 242, 
   47, 135, 135, 184, 184, 111, 111, 111,  63,  63, 119, 127, 119,  92,  92,  89,  89,  64,  59,  64, 
   30,  64,  64, 146, 146, 146,  50, 191, 190, 190, 128, 128, 112, 211, 103, 103,  43,  41,  41, 162, 
  162,  74,  74,  51,  82,  51,  82, 163, 163,  30,  30, 101, 101,  27,  27, 209, 209,  99,  99,  40, 
   40,   9,   4,   4, 178, 178, 178,  52, 173, 147, 153, 147, 153, 134, 211, 134, 191,  61, 118, 118, 
  131, 179, 136, 181, 136, 112, 109,  21, 109, 187, 187, 204, 186, 180, 140, 131,  95,  95, 126, 126, 
   55,  55,  55,  21,  21,  26,  26,  26, 110, 203, 168, 168, 164, 164, 225, 225, 213, 168, 168, 118, 
  134, 118,  29,  29, 143, 143, 135,  77,  77, 183, 183, 231, 104,  99,  99, 104, 104,  78,  78, 111, 
  143, 231, 231, 151, 151, 131, 177, 104, 127,  77,  51,  51, 109, 157, 241, 157, 123, 123, 123, 133, 
  175, 175, 156,  47, 156,  80,  80,  27,  27,  28,  70,  99,  99,  62,  47,  62, 124, 124,  27,  27, 
  179, 192, 192, 197, 197, 197, 165, 111,  83,   0
};

