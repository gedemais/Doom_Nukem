#include "main.h"

static char	*spaths(unsigned int index)
{
	static char		*paths[NB_SAMPLES] = {"resources/samples/sound.wav"};

	return (paths[index]);
}

static int			create_buffers(t_sample *samples)
{
	unsigned int	i;
	t_sample		*s;

	i = 0;
	while (i < NB_SAMPLES)
	{
		s = &samples[i];
		alGenBuffers(1, &s->buffer);
		alBufferData(s->buffer, s->format, s->sample, s->nb_samples * (int)sizeof(ALshort), s->sample_rate);
		if (alGetError() != AL_NO_ERROR)
			return (-1);
		i++;
	}
	return (0);
}

static int			read_samples(t_sample *samples)
{
	unsigned int	i;

	i = 0;
	while (i < NB_SAMPLES)
	{
		if (!(samples[i].sample = (ALshort*)malloc(sizeof(ALshort) * (unsigned)samples[i].nb_samples)))
			return (-1);
		if (sf_read_short(samples[i].file, samples[i].sample,
			samples[i].nb_samples) < samples[i].nb_samples)
			return (-1);
		sf_close(samples[i].file);
		i++;
	}
	return (0);
}

static t_sample	*load_samples(void)
{
	t_sample		*dest;
	t_sample		t;
	unsigned int	i;

	i = 0;
	if (!(dest = (t_sample*)malloc(sizeof(t_sample) * NB_SAMPLES)))
		return (NULL);
	while (i < NB_SAMPLES)
	{
		if (!(t.file = sf_open(spaths(i), SFM_READ, &t.infos)))
		{
			ft_putstr_fd(spaths(i), 2);
			ft_putstr_fd(SAMPLE_NF, 2);
			return (NULL);
		}
		t.sample_rate = (ALsizei)t.infos.samplerate;
		t.nb_samples = (ALsizei)(t.infos.channels * t.infos.frames);
		t.format = t.infos.channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
		ft_memcpy(&dest[i], &t, sizeof(t_sample));
		i++;
	}
	if (read_samples(dest) || create_buffers(dest))
		return (NULL);
	return (dest);
}

int			init_openal(t_sound *env)
{
	if (!(env->device = alcOpenDevice(NULL)))
	{
		ft_putstr_fd(OPEN_DEVICE, 2);
		return (-1);
	}
	if (!(env->context = alcCreateContext(env->device, NULL)))
	{
		ft_putstr_fd(CREATE_CONTEXT, 2);
		return (-1);
	}
	if (!(alcMakeContextCurrent(env->context)))
	{
		ft_putstr_fd(CONTEXT_CURRENT, 2);
		return (-1);
	}
	if (!(env->samples = load_samples()))
		return (-1);
	return (0);
}
