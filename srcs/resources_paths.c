#include "main.h"

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
					"resources/sprites/grass.XPM"};

	return (paths[index]);
}

char	*samples_paths(unsigned int index)
{
	static char		*paths[SA_MAX] = {
					"resources/samples/ambiances/ambient_.wav"};

	return (paths[index]);
}
