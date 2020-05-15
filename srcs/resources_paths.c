#include "main.h"

char	*maps_paths(unsigned int index)
{
	static char	*paths[SCENE_MAX] = {	"resources/maps/famas.obj",
										"resources/maps/ak47.obj",
										"resources/maps/sawed-off.obj",
										"resources/maps/glock-18.obj",
										"resources/maps/aug.obj",
										"resources/maps/ump45.obj",
										"resources/maps/mag-7.obj",
										"resources/maps/cube.obj",
										"resources/maps/axis.obj",
										"resources/maps/pente_nord.obj",
										"resources/maps/pente_ouest.obj",
										"resources/maps/pentg_sud.obj",
										"resources/maps/pente_est.obj",
										"resources/maps/map-test.obj"};

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
					"resources/sprites/buttons/SP_NM_BUTTON_MAPED_2C.xpm",
					"resources/sprites/buttons/SP_NM_BUTTON_MAPED_2H.xpm",
					"resources/sprites/buttons/SP_NM_BUTTON_MAPED_2O.xpm",
					"resources/sprites/ts_background.XPM",
					"resources/sprites/cmp_ts_background.XPM",
					"resources/sprites/main_txt_loader_campaign.XPM",
					"resources/sprites/map_editor_background.xpm",
					"resources/sprites/me_new_map_background.xpm",
					"resources/sprites/map_editor_menu_title.xpm",
					"resources/sprites/map_editor_new_map_title.xpm",
					"resources/sprites/custom_background.xpm"};

	return (paths[index]);
}

char	*blocs_txt_paths(unsigned int index)
{
	static char		*paths[BTXT_MAX] = {"",
		"resources/textures/blocs/brique.xpm",
		"resources/textures/blocs/brique_dark.xpm",
		"resources/textures/blocs/clean_stone.xpm",
		"resources/textures/blocs/dirt.xpm",
		"resources/textures/blocs/dirt_grass.xpm",
		"resources/textures/blocs/dirt_snow.xpm",
		"resources/textures/blocs/glace.xpm",
		"resources/textures/blocs/gold.xpm",
		"resources/textures/blocs/iron.xpm",
		"resources/textures/blocs/library.xpm",
		"resources/textures/blocs/light.xpm",
		"resources/textures/blocs/obsidienne.xpm",
		"resources/textures/blocs/sand.xpm",
		"resources/textures/blocs/stone.xpm",
		"resources/textures/blocs/wood_a.xpm",
		"resources/textures/blocs/wood_a_cut.xpm",
		"resources/textures/blocs/wood_b.xpm",
		"resources/textures/blocs/wood_b_cut.xpm",
		"resources/textures/blocs/wood_c.xpm",
		"resources/textures/blocs/wood_c_cut.xpm",
		"resources/textures/blocs/wood_d.xpm",
		"resources/textures/blocs/wood_d_cut.xpm",
		"resources/textures/blocs/jukebox.xpm"};

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
