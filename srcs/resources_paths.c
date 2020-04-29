#include "main.h"

char	*maps_paths(unsigned int index)
{
	static char	*paths[SCENE_MAX] = {	"resources/maps/physic_02.obj",
										"resources/maps/famas.obj",
										"resources/maps/ak47.obj",
										"resources/maps/sawed-off.obj",
										"resources/maps/glock-18.obj",
										"resources/maps/aug.obj",
										"resources/maps/ump45.obj",
										"resources/maps/e1.obj",
										"resources/maps/sector_a.obj",
										"resources/maps/sector_b.obj",
										"resources/maps/sector_c.obj",
										"resources/maps/cube.obj"};

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
					"resources/sprites/logo.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_1C.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_1H.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_1O.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_2C.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_2H.XPM",
					"resources/sprites/buttons/SP_CP_BUTTON_2O.XPM",
					"resources/sprites/buttons/SP_ME_BUTTON_2C.XPM",
					"resources/sprites/buttons/SP_ME_BUTTON_2H.XPM",
					"resources/sprites/buttons/SP_ME_BUTTON_2O.XPM",
					"resources/sprites/buttons/SP_ME_BUTTON_CREATE_1C.xpm",
					"resources/sprites/buttons/SP_ME_BUTTON_CREATE_1H.xpm",
					"resources/sprites/buttons/SP_ME_BUTTON_CREATE_1O.xpm",
					"resources/sprites/ts_background.XPM",
					"resources/sprites/cmp_ts_background.XPM",
					"resources/sprites/main_txt_loader_campaign.XPM",
					"resources/sprites/map_editor_background.xpm",
					"resources/sprites/me_new_map_background.xpm",
					"resources/sprites/map_editor_menu_title.xpm",
					"resources/sprites/map_editor_new_map_title.xpm"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {"resources/samples/ambiances/title_screen_intro.wav",
					"resources/samples/ambiances/title_screen_loop.wav",
					"resources/samples/loop.wav"};

	return (paths[index]);
}

char	*fonts_paths(unsigned int index)
{
	static char		*paths[FONT_MAX] = {"resources/fonts/arial.ttf",
										"resources/fonts/ammos.ttf",
										"resources/fonts/Courier.dfont",
										"resources/fonts/coolvetica.ttf"};

	return (paths[index]);
}
