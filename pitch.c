#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int seq(char c, int n)
{
  char *tune = "C D EF G A B";
  return (n * 12 + strchr(tune, c) - tune);
}

double freq(char *name)
{
  if (strcmp(name, "pause") == 0)
    return 0.0;
  assert(strlen(name) == 2 || strlen(name) == 3);
  char c = name[0];
  int n = name[1] - '0';
  assert(c >= 'A' && c <= 'G' && n >= 0 && n < 8);  
  const double r = 1.0594630943593;
  int diff = seq(c, n) - seq('A', 4);

  double f = 440.0;
  if (diff >= 0) {
    int oct = diff / 12;
    int inc = diff % 12;
    for (int i = 0; i < oct; i++)
      f *= 2.0;
    for (int i = 0; i < inc; i++)
      f *= r;
  } else {
    diff = -diff;
    int oct = diff / 12;
    int inc = diff % 12;
    for (int i = 0; i < oct; i++)
      f /= 2.0;
    for (int i = 0; i < inc; i++)
      f /= r;
  }
  if (strlen(name) == 3) {
    switch (name[2]) {
    case '#':
      f *= r;
      break;
    case 'b':
      f /= r;
      break;
    default:
      printf("invalid char %c\n", name[2]);
    }
  }
  return f;
}

typedef struct note
{
  double frequency;
  double duration;
} Note;

typedef struct WAVheader
{
  char RIFF[4];
  int chunkSize;
  char wave[4];
  char format[4];
  int subChunkSize;
  short audioFormat;
  short numChannel;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  char data[4];
  int dataSize;
} WAVHeader;

#define SAMPLE 65536
#define LOWFREQTHRESHOLD 100
#define MAGNIFYFACTOR 20000

#define min(a, b) (a < b? a:b)

int genWAV(Note note[], int n, FILE *fp, WAVHeader header)
{
  int i, j, noteNum;
  int dataSize = 0;
  const double PI = 3.1415926;
  short sample[SAMPLE];
  short zero[SAMPLE] = {0};

  for (noteNum = 0; noteNum < n; noteNum++) {
    int frequency = note[noteNum].frequency;
    int numOfSamples = note[noteNum].duration * header.sampleRate;

    if (frequency < LOWFREQTHRESHOLD) {
      int samplesToWrite = 2 * numOfSamples; /* two channels */
      while (samplesToWrite > 0) {
	fwrite(zero, sizeof(short), min(SAMPLE, samplesToWrite), fp);
	dataSize += sizeof(short) * min(SAMPLE, samplesToWrite);
	samplesToWrite -= min(SAMPLE, samplesToWrite);
      }
    }
    else {
      int samplePerCycle = header.sampleRate / (double)frequency;
      double duration = note[noteNum].duration;
      int numCycle = (int)(duration * frequency);
      double delta = (2.0 * PI) / samplePerCycle;
    
      printf("%d samples per second\n", header.sampleRate);
      printf("%d samples per cycle\n", samplePerCycle);
      printf("%d cycles to write\n", numCycle);

      assert(samplePerCycle < SAMPLE);
      for (i = 0; i < samplePerCycle; i++) {
	sample[i] = sin(delta * i) * MAGNIFYFACTOR;
      }
      for (i = 0; i < numCycle; i++) {
	for (j = 0; j < samplePerCycle; j++) {
	  fwrite(&(sample[j]), sizeof(short), 1, fp);
	  fwrite(&(sample[j]), sizeof(short), 1, fp);
	  dataSize += 2 * sizeof(short);
	}
      }
    }
  }
  return dataSize;
}

#define MAXNOTE 1024

int main()
{
  WAVHeader header = {
    {'R', 'I', 'F', 'F'}, 0, {'W', 'A', 'V', 'E'}, {'f', 'm', 't', ' '},
    16, 1, 2, 44100, 176400, 4, 16, {'d', 'a', 't', 'a'}, 0
  };
  int dataSize = 0;
  Note note[MAXNOTE];

  char name[4];
  double beat;
  int i = 0;
  int beatPerSecond;
  scanf("%d", &beatPerSecond);
  while (scanf("%lf%s", &beat, name) != EOF) {
    note[i].frequency = freq(name);
    note[i].duration = (60.0 / beatPerSecond) * beat;
    printf("%f %f\n", note[i].frequency, note[i].duration);
    i++;
  }
  
  FILE *fp;
  fp = fopen("sample.wav", "wb");
  fwrite(&header, sizeof(WAVHeader), 1, fp);

  dataSize = genWAV(note, i, fp, header);
  printf("dataSize = %d\n", dataSize);
  int chunkSize = dataSize + 36;
  printf("chunkSize = %d\n", chunkSize);
  fseek(fp, 4, SEEK_SET);
  fwrite(&chunkSize, sizeof(int), 1, fp);
  fseek(fp, 40, SEEK_SET);
  fwrite(&dataSize, sizeof(int), 1, fp);
  fclose(fp);
  return 0;
}
