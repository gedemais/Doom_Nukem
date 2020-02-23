#include "main.h"

char	*maps_paths(unsigned int index)
{
	static char	*paths[SCENE_MAX] = {	"resources/maps/physic_01.obj",
										"resources/maps/cube_textured.obj", 
										"resources/maps/monsters.obj"};

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
					"resources/textures/texture.XPM"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {
					"resources/samples/ambiances/title_screen_intro.wav",
					"resources/samples/ambiances/title_screen_loop.wav"};

	return (paths[index]);
}
