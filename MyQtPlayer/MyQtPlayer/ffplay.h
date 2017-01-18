#ifndef __FFPLAY_H__
#define __FFPLAY_H__

struct VideoState;
class XYPlayViewHandler
{
public:
	virtual void allocTexture(VideoState* is, void *srcFrame) = 0;
	virtual void drawTexture(VideoState *is, float *remaining_time) = 0;
	virtual void setProgress(int pos) = 0;
protected:
	virtual ~XYPlayViewHandler() {}
public:

	int m_nProcess;

};
//funs
VideoState* ffplay(char *fileName,  void *winId);
void playSetCtl(XYPlayViewHandler* ctl);
void playPause(VideoState*player);
void playSeek(double frac);
void playStop(VideoState **player);
void playVideoRefresh(VideoState *is, float *remaining_time);
void playAllocPicture(VideoState *is, void *src);
void deleteView();

#endif