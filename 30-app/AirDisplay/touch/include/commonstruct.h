
#define TP_MAXLEN_ENCRYPTKEY			128

// ý������
enum EmTpMediaType
{
	emTPMediaVideo = 1, //��Ƶ
	emTPMediaAudio = 2, //��Ƶ
	emTPMediaAV    = 3, //��Ƶ����Ƶ
	emTPMediaMerge = 4 //����ϳ�
};

//�ؼ�֡���
enum EmTpIFrameCheckType
{
	TP_IFrameCheck_Speaker,				//��ⷢ����
	TP_IFrameCheck_SingleSpeaker,		//
	TP_IFrameCheck_Poll,				//��ѯ����
	TP_IFrameCheck_ChairWait,			//��ϯ����ʱ���л������������ˣ���ϯ�ļ��
};

