#include "stdio.h"
#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

int main() {
  drwav wav;
  if (!drwav_init_file(&wav, "8000hz_1ch_16bit.wav", NULL)) {
    printf("..Exit()..\tend\n");
    return 0;
  }

  drwav_int32* pDecodedInterleavedPCMFrames = malloc(wav.totalPCMFrameCount * wav.channels * sizeof(drwav_int32));
  size_t numberOfSamplesActuallyDecoded = drwav_read_pcm_frames_s32(&wav, wav.totalPCMFrameCount, pDecodedInterleavedPCMFrames);
  printf("totalPCMFrameCount=%llu\n",wav.totalPCMFrameCount);
  drwav_uninit(&wav);
  printf("..Run..\tend\n");
  return 0;
}