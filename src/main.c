#include <alsa/asoundlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#define size 10512

const char* device = "default";
int buffer[size*16];

int main()
{
    snd_pcm_t *handle;
    int error;
    for (int i = 0; i < size*16; i++) {
        buffer[i] = (random()%65536) - 32768;
    }
    if ((error = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK)) < 0) {
        fprintf(stderr, "Failed to open device: %s\n", snd_strerror(error));
        return 1;
    }
    if ((error = snd_pcm_set_params(handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED, 1, 42000, 1, 300000) < 0)) {
        fprintf(stderr, "Failed to set params: %s\n", snd_strerror(error));
        return 1;
    }
    for (int i = 0; i<24; i++) {
        snd_pcm_writei(handle, buffer, size);
    }
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    return 0;
}
