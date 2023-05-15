#include "main.h"

/**
 * Reads data from a file descriptor into a buffer.
 *
 * @param fd     File descriptor to read from.
 * @param buf    Buffer to store the read data.
 * @param count  Maximum number of bytes to read.
 * @return       Number of bytes read on success, -1 on error (with `errno` set).
 */
ssize_t my_read(int fd, void *buf, size_t count)
{
	if (buf == NULL || count == 0)
	{
		errno = EINVAL; /*Invalid argument*/
		return -1;
	}
	ssize_t total = 0;
	char *buffer = (char *)buf;

	while (total < count)
	{
		ssize_t bytes_read = read(fd, buffer + total, count - total);

		if (bytes_read == -1)
		{
			/*Error occurred*/
			errno = EIO; /*I/O error*/

			return -1;
		} else if (bytes_read == 0)
		{
            /*End of file or connection closed*/
			break;
		}

		total += bytes_read;
	}

	return total;
}
