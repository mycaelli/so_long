#include "../game/game.h"
#include "../sprites/sprites.h"
#include "../movements/movements.h"
//#include <X11/keysym.h> //EXCLUIR
#include "../game/game.h"

#define XK_Escape                        0xff1b
#define XK_A                             0x0041  /* U+0041 LATIN CAPITAL LETTER A */
#define XK_D                             0x0044  /* U+0044 LATIN CAPITAL LETTER D */
#define XK_W                             0x0057  /* U+0057 LATIN CAPITAL LETTER W */
#define XK_S                             0x0053  /* U+0053 LATIN CAPITAL LETTER S */

#define XK_a                             0x0061  /* U+0061 LATIN SMALL LETTER A */
#define XK_d                             0x0064  /* U+0064 LATIN SMALL LETTER D */
#define XK_w                             0x0077  /* U+0077 LATIN SMALL LETTER W */
#define XK_s                             0x0073  /* U+0073 LATIN SMALL LETTER S */

void	close_win(t_game *game);
int	key_input(int key, t_game *game);
void	move_character(t_game *game);
char	find_wall(int key, t_game *game);
void	print_movements(t_game *game);