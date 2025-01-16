#include "so_long.h"

char	*extract_line(char *aux_read)
{
	int		i;
	char	*aux;

	i = 0;
	while (aux_read[i] != '\0' && aux_read[i] != '\n')
		i++;
	if (aux_read[i] == '\n')
		i++;
	aux = malloc((i + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (aux_read[i] != '\0' && (i == 0 || aux_read[i - 1] != '\n'))
	{
		aux[i] = aux_read[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*remove_first_line(char *statica)
{
	char	*new_static;
	int		i;
	int		j;
	int		k;
	int		len_new_static;

	len_new_static = 0;
	i = 0;
	j = 0;
	while (statica[i] != '\0' && statica[i] != '\n')
		i++;
	if (statica[i] == '\0')
		return (free(statica), NULL);
	i++;
	k = i;
	while (statica[i++] != '\0')
		len_new_static++;
	new_static = malloc((len_new_static + 1) * sizeof(char));
	if (new_static == NULL)
		return (free(statica), NULL);
	while (statica[k] != '\0')
		new_static[j++] = statica[k++];
	new_static[j] = '\0';
	free(statica);
	return (new_static);
}

char	*aux_get_read(int fd, char *statica, char *aux_read)
{
	int	val_read;

	val_read = 1;
	while (val_read != 0 && !mystrchr(statica, '\n'))
	{
		val_read = read(fd, aux_read, BUFFER_SIZE);
		if (val_read < 0)
			return (free(statica), free(aux_read), statica = NULL);
		aux_read[val_read] = '\0';
		statica = mystrjoin(statica, aux_read);
		if (!statica)
			return (free(statica), free(aux_read), statica = NULL);
	}
	free(aux_read);
	return (statica);
}

char	*get_read(int fd, char *statica)
{
	char	*aux_read;

	aux_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_read)
	{
		if (statica)
			return (free(statica), NULL);
		return (NULL);
	}
	else if (statica == NULL)
	{
		statica = malloc(BUFFER_SIZE * sizeof(char));
		if (!statica)
			return (free(aux_read), NULL);
		statica[0] = '\0';
	}
	statica = aux_get_read(fd, statica, aux_read);
	return (statica);
}

char	*get_next_line(int fd)
{
	static char	*statica = NULL;
	char		*line;

	statica = get_read(fd, statica);
	if (statica == NULL)
		return (NULL);
	if (statica[0] == '\0')
		return (free(statica), statica = NULL);
	line = extract_line(statica);
	if (line == NULL)
		return (free(statica), statica = NULL);
	statica = remove_first_line(statica);
	return (line);
}
