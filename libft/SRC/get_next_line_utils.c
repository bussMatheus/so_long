#include "../libft.h"

static char	*ft_strdupp(char *s)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static void	ft_joining(char *s1, char *buffer, char *new_s)
{
	ssize_t		i;
	ssize_t		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		new_s[i + j] = buffer[j];
		j++;
	}
	if (buffer [j] == '\n')
		new_s[i + j++] = '\n';
	new_s[i + j] = 0;
}

char	*ft_strjoin_gnl(char *s1, char *buffer)
{
	char	*new_s;

	if (!s1)
		s1 = ft_strdupp("");
	if (!s1)
		return (NULL);
	new_s = malloc((ft_strlen(s1) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!new_s)
	{
		free(s1);
		return (NULL);
	}
	ft_joining(s1, buffer, new_s);
	free(s1);
	return (new_s);
}

int	cut_remaining(char *buf)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    if (buf[i] == '\n')
    {
        i++;
        while (buf[i])
        	buf[j++] = buf[i++];
    	buf[j] = '\0';
		return (1);
    }
	buf[0] = '\0';
	return (0);
}
