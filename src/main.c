#include <alsa/asoundlib.h>
#include <stdio.h>

const char* device = "default";

int main()
{
    snd_pcm_t *handle;
    int error;
    if ((error = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK)) < 0) {
        fprintf(stderr, "Failed to open device: %s\n", snd_strerror(error));
        return 1;
    }
    if ((error = snd_pcm_set_params(handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED, 2, 92000, 1, 300000) < 0))
    {
        fprintf(stderr, "Failed to set params: %s\n", snd_strerror(error));
        return 1;
    }
    snd_pcm_close(handle);
    return 0;
}
