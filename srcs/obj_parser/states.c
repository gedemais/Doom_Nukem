#include "main.h"


void	init_states(char states[NB_LINE_TYPES][NB_LINE_TYPES])
{
	states[PS_OBJ][PS_OBJ] = 0;
	states[PS_OBJ][PS_VERTEXS] = 1;
	states[PS_OBJ][PS_TXT_VERTEXS] = 0;
	states[PS_OBJ][PS_END_VERTEXS] = 0;
	states[PS_OBJ][PS_FACES] = 0;
	states[PS_OBJ][PS_COMMENT] = 1;

	states[PS_VERTEXS][PS_OBJ] = 0;
	states[PS_VERTEXS][PS_VERTEXS] = 1;
	states[PS_VERTEXS][PS_TXT_VERTEXS] = 1;
	states[PS_VERTEXS][PS_END_VERTEXS] = 1;
	states[PS_VERTEXS][PS_FACES] = 0;
	states[PS_VERTEXS][PS_COMMENT] = 1;

	states[PS_END_VERTEXS][PS_OBJ] = 0;
	states[PS_END_VERTEXS][PS_VERTEXS] = 0;
	states[PS_END_VERTEXS][PS_TXT_VERTEXS] = 0;
	states[PS_END_VERTEXS][PS_END_VERTEXS] = 0;
	states[PS_END_VERTEXS][PS_FACES] = 1;
	states[PS_END_VERTEXS][PS_COMMENT] = 1;

	states[PS_TXT_VERTEXS][PS_OBJ] = 0;
	states[PS_TXT_VERTEXS][PS_VERTEXS] = 1;
	states[PS_TXT_VERTEXS][PS_TXT_VERTEXS] = 1;
	states[PS_TXT_VERTEXS][PS_END_VERTEXS] = 1;
	states[PS_TXT_VERTEXS][PS_FACES] = 0;
	states[PS_TXT_VERTEXS][PS_COMMENT] = 1;

	states[PS_FACES][PS_OBJ] = 1;
	states[PS_FACES][PS_VERTEXS] = 0;
	states[PS_FACES][PS_TXT_VERTEXS] = 1;
	states[PS_FACES][PS_END_VERTEXS] = 0;
	states[PS_FACES][PS_FACES] = 1;
	states[PS_FACES][PS_COMMENT] = 1;

	ft_memset(&states[PS_COMMENT], 1, sizeof(char) * NB_LINE_TYPES);
}
