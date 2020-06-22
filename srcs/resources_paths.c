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
										"resources/maps/galil.obj",
										"resources/maps/negev.obj",
										"resources/maps/tec-9.obj",
										"resources/maps/physic.obj",
										"resources/maps/cube.obj",
										"resources/maps/axis.obj",
										"resources/maps/pente_nord.obj",
										"resources/maps/pente_ouest.obj",
										"resources/maps/pente_sud.obj",
										"resources/maps/pente_est.obj",
										"resources/maps/map-test.obj",
										"resources/maps/slender.obj",
										"resources/maps/ugly.obj",
										"resources/maps/mad.obj"};

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
					"resources/sprites/custom_background.xpm",
					"resources/sprites/hitmarker.xpm"};

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
		"resources/textures/blocs/jukebox.xpm",
		"resources/textures/blocs/mystery_box.xpm",
		"resources/textures/blocs/door.xpm",
		"resources/textures/blocs/lava.xpm",
		"resources/textures/blocs/spawner.xpm",
		"resources/textures/blocs/mob_spawner.xpm"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {"resources/samples/ambiances/title_screen_intro.wav",
					"resources/samples/ambiances/title_screen_loop.wav",
					"resources/samples/loop.wav",
					"resources/samples/weapons/ak47-reload.wav",
					"resources/samples/weapons/ak47-shot.wav",
					"resources/samples/weapons/aug-reload.wav",
					"resources/samples/weapons/aug-shot.wav",
					"resources/samples/weapons/famas-reload.wav",
					"resources/samples/weapons/famas-shot.wav",
					"resources/samples/weapons/galil-reload.wav",
					"resources/samples/weapons/galil-shot.wav",
					"resources/samples/weapons/glock-reload.wav",
					"resources/samples/weapons/glock-shot.wav",
					"resources/samples/weapons/mag7-reload.wav",
					"resources/samples/weapons/mag7-shot.wav",
					"resources/samples/weapons/negev-reload.wav",
					"resources/samples/weapons/negev-shot.wav",
					"resources/samples/weapons/sawed-off-fill.wav",
					"resources/samples/weapons/sawed-off-pump.wav",
					"resources/samples/weapons/sawed-off-shot.wav",
					"resources/samples/weapons/tec9-reload.wav",
					"resources/samples/weapons/tec9-shot.wav",
					"resources/samples/weapons/ump45-reload.wav",
					"resources/samples/weapons/ump45-shot.wav",
					"resources/samples/voices/doublekill.wav",
					"resources/samples/voices/triplekill.wav",
					"resources/samples/voices/rampage.wav",
					"resources/samples/voices/godlike.wav",
					"resources/samples/voices/wickedsick.wav",
					"resources/samples/monsters/death_monster.wav",
					"resources/samples/world/door.wav",
					"resources/samples/world/gong.wav",
					"resources/samples/world/invocation.wav",
					"resources/samples/world/ring.wav",
					"resources/samples/world/portail.wav",
					"resources/samples/world/teleportation.wav",};

	return (paths[index]);
}

char	*icones_paths(unsigned int index)
{
	static char		*paths[BTXT_MAX] = {"brick_ico.xpm", "dark_brick_ico.xpm",
										"clean_stone_ico.xpm", "dirt_ico.xpm",
										"dirt_grass_ico.xpm",
										"dirt_snow_ico.xpm",
										"glace_ico.xpm",
										"gold_ico.xpm",
										"iron_ico.xpm",
										"light_ico.xpm",
										"obsidienne_ico.xpm",
										"sand_ico.xpm",
										"stone_ico.xpm",
										"wood_a_ico.xpm",
										"wood_a_cut_ico.xpm",
										"wood_b_ico.xpm",
										"wood_b_cut_ico.xpm",
										"wood_c_ico.xpm",
										"wood_c_cut_ico.xpm",
										"wood_d_ico.xpm",
										"wood_d_cut_ico.xpm",
										"jukebox_ico.xpm",
										"mystery_box_ico.xpm",
										"door_ico.xpm",
										"lava_ico.xpm",
										"spawner_ico.xpm",
										"mob_spawner_ico.xpm"};
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
