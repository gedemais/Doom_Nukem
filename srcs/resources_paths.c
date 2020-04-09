#include "main.h"

char	*maps_paths(unsigned int index)
{
	static char	*paths[SCENE_MAX] = {	"resources/maps/famas.obj",
										"resources/maps/ak47.obj",
										"resources/maps/sawed-off.obj",
										"resources/maps/glock-18.obj",
										"resources/maps/aug.obj",
										"resources/maps/ump45.obj"};

	return (paths[index]);
}

char	*sprites_paths(unsigned int index)
{
	static char		*paths[SP_MAX] = {
					"resources/sprites/buttons/campaign_clic.XPM",
					"resources/sprites/buttons/campaign_hover.XPM",
					"resources/sprites/buttons/campaign_off.XPM",
					"resources/sprites/buttons/custom_clic.XPM",
					"resources/sprites/buttons/custom_hover.XPM",
					"resources/sprites/buttons/custom_off.XPM",
					"resources/sprites/buttons/map_editor_clic.XPM",
					"resources/sprites/buttons/map_editor_hover.XPM",
					"resources/sprites/buttons/map_editor_off.XPM",
					"resources/sprites/buttons/quit_clic.XPM",
					"resources/sprites/buttons/quit_hover.XPM",
					"resources/sprites/buttons/quit_off.XPM",
					"resources/sprites/ts_background.XPM",
					"resources/sprites/logo.XPM",
					"resources/textures/texture.XPM",
					"resources/sprites/main_txt_loader_campaign.XPM",
					"resources/sprites/Doom_first_loader.XPM",
					"resources/sprites/SP_Board_Button.xpm",
					"resources/sprites/SP_CP_BUTTON_1C.XPM",
					"resources/sprites/SP_CP_BUTTON_1H.XPM",
					"resources/sprites/SP_CP_BUTTON_1O.XPM",
					"resources/sprites/SP_CP_BUTTON_2C.XPM",
					"resources/sprites/SP_CP_BUTTON_2H.XPM",
					"resources/sprites/SP_CP_BUTTON_2O.XPM",
					"resources/sprites/SP_CP_BUTTON_3C.XPM",
					"resources/sprites/SP_CP_BUTTON_3H.XPM",
					"resources/sprites/SP_CP_BUTTON_3O.XPM",
					"resources/sprites/map_editor_background.xpm",
					"resources/sprites/ME_TITLE.xpm",
					"resources/sprites/SP_ME_RECT_PRW.xpm",
					"resources/sprites/SP_ME_RECT_BTN.xpm",
					"resources/sprites/SP_ME_BUTTON_LD_C.xpm",
					"resources/sprites/SP_ME_BUTTON_LD_H.xpm",
					"resources/sprites/SP_ME_BUTTON_LD_O.xpm",
					"resources/sprites/SP_ME_BUTTON_NW_C.xpm",
					"resources/sprites/SP_ME_BUTTON_NW_H.xpm",
					"resources/sprites/SP_ME_BUTTON_NW_O.xpm",
					"resources/sprites/SP_ME_BUTTON_TX_C.xpm",
					"resources/sprites/SP_ME_BUTTON_TX_H.xpm",
					"resources/sprites/SP_ME_BUTTON_TX_O.xpm",
					"resources/sprites/SP_ME_BUTTON_OBJ_C.xpm",
					"resources/sprites/SP_ME_BUTTON_OBJ_H.xpm",
					"resources/sprites/SP_ME_BUTTON_OBJ_O.xpm",
					"resources/sprites/SP_ME_BUTTON_MN_C.xpm",
					"resources/sprites/SP_ME_BUTTON_MN_H.xpm",
					"resources/sprites/SP_ME_BUTTON_MN_O.xpm"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {
					"resources/samples/ambiances/title_screen_intro.wav",
					"resources/samples/ambiances/title_screen_loop.wav"};

	return (paths[index]);
}

char	*fonts_paths(unsigned int index)
{
	//static char		*paths[FONT_MAX] = {"resources/fonts/AmazDooMRight.ttf"};
	static char		*paths[FONT_MAX] = {"/usr/local/Homebrew/Library/Homebrew/vendor/portable-ruby/2.6.3/lib/ruby/2.6.0/rdoc/generator/template/darkfish/fonts/SourceCodePro-Bold.ttf"};
	
	return (paths[index]);
}
