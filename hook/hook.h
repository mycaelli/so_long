#include "../window/window.h"
#include "../sprites/sprites.h"
//#include <X11/keysym.h> //EXCLUIR
#include "../window/window.h"

#define XK_Escape                        0xff1b
#define XK_A                             0x0041  /* U+0041 LATIN CAPITAL LETTER A */
#define XK_D                             0x0044  /* U+0044 LATIN CAPITAL LETTER D */
#define XK_W                             0x0057  /* U+0057 LATIN CAPITAL LETTER W */
#define XK_S                             0x0053  /* U+0053 LATIN CAPITAL LETTER S */

#define XK_a                             0x0061  /* U+0061 LATIN SMALL LETTER A */
#define XK_d                             0x0064  /* U+0064 LATIN SMALL LETTER D */
#define XK_w                             0x0077  /* U+0077 LATIN SMALL LETTER W */
#define XK_s                             0x0073  /* U+0073 LATIN SMALL LETTER S */

int	close_win(int keysym, t_window *window);