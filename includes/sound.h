#ifndef SOUND_H
# define SOUND_H

# include <AL/al.h>
# include <AL/alc.h>
# include <sndfile.h>

enum	e_sample_id
{
	SA_TITLE_SCREEN_S,
	SA_TITLE_SCREEN_L,
	SA_PNL,
	SA_AK47_RELOAD,
	SA_AK47_FIRE,
	SA_AUG_RELOAD,
	SA_AUG_FIRE,
	SA_FAMAS_RELOAD,
	SA_FAMAS_FIRE,
	SA_GALIL_RELOAD,
	SA_GALIL_FIRE,
	SA_GLOCK_RELOAD,
	SA_GLOCK_FIRE,
	SA_MAG7_RELOAD,
	SA_MAG7_FIRE,
	SA_NEGEV_RELOAD,
	SA_NEGEV_FIRE,
	SA_SAWED_OFF_FILL,
	SA_SAWED_OFF_PUMP,
	SA_SAWED_OFF_FIRE,
	SA_TEC9_RELOAD,
	SA_TEC9_FIRE,
	SA_UMP45_RELOAD,
	SA_UMP45_FIRE,
	SA_DOUBLEKILL,
	SA_TRIPLEKILL,
	SA_RAMPAGE,
	SA_GODLIKE,
	SA_WICKEDSICK,
	SA_DEATHMONSTER,
	SA_DOOR,
	SA_GONG,
	SA_INVOCATION,
	SA_RING,
	SA_PORTAIL,
	SA_TELEPORTATION,
	SA_LNUKE,
	SA_LAMMOS,
	SA_LCASH,
	SA_LGODSTART,
	SA_LGODEND,
	SA_MAX
};

typedef struct	s_sample
{
	//char		*name;
	ALuint		buffer;
	ALshort		*sample;
	SNDFILE		*file;
	SF_INFO		infos;
	ALenum		format;
	ALsizei		sample_rate;
	ALsizei		nb_samples;
	float		length;
}				t_sample;

typedef struct	s_sound_param
{
	bool		stop;
	bool		overall;
	bool		fork;
	bool		sound;
	size_t		pause;
	float		volume;
}				t_sparam;

typedef struct	s_sound
{
	ALCdevice	*device;
	ALCcontext	*context;
	t_sample	*samples;
	ALuint		ambient;
}				t_sound;

int				sound_system(t_env *env, int source, t_sparam param);

char			*samples_paths(unsigned int index);

#endif
