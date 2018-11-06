//�g�p����w�b�_�[�t�@�C��
#include <stdlib.h>
#include <time.h>
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjMap1.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjMap1::CObjMap1(int map[56][56])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(56 * 56));
}

//�C�j�V�����C�Y
void CObjMap1::Init()
{
	srand(time(NULL));
	x = -1800;
	y = -1300;
	m_scroll = 0.0f;
	m_scrolly = 0.0f;

	//�K�i�o���ʒu�̐ݒ�
	while (1)
	{
		for (int i = 0; i < 56; i++)
		{
			for (int j = 0; j < 56; j++)
			{
				//�Q�𔭌�
				if (m_map[i][j] == 2)
				{
					//2�̒�����1�K�i���o��������
					int stair = 0;

					stair = rand() % 3;
					if (stair == 1)
					{
						m_map[i][j] = 4;
						return;
					}
				}
			}
		}
	}
}
//�A�N�V����
void CObjMap1::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�����X�N���[�����C��
//	if (hx < 80)
	{
		hero->SetX(0);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}
	//�E���X�N���[�����C��
//	if (hx > 300)
	{
		hero->SetX(400);				
		m_scroll -= hero->GetVX();		
	}
	//����X�N���[�����C��
	{
		hero->SetY(0);
		m_scrolly -= hero->GetVY();
	}
	//�����X�N���[�����C��
	{
		hero->SetY(300);
		m_scrolly -= hero->GetVY();
	}


	/*//�G�o�����C��
	//��l���̈ʒu+500��G�o�����C���ɂ���
	float line = hx + (-m_scroll) + 500;

	//�G�o�����C����v�f�ԍ���
	int ex = ((int)line) / 64;

	//�G�o�����C���̗������
	for (int i = 0; i < 10; i++)
	{
		//��̒�����4��T��
		if (m_map[i][ex] == 4)
		{

			//4������ΓG���o��
			CObjEnemy* obje = new CObjEnemy(ex*64.0f, i*64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 10);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
	}*/
}
//�h���[
void CObjMap1::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�}�b�v�`�b�v�ɂ��block�z�u
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] >= 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*50.0f + m_scrolly + y;				//�}�b�v�T�C�Y,�����ʒu
				dst.m_left = j*50.0f + m_scroll + x;
				dst.m_right = dst.m_left + 50.0;
				dst.m_bottom = dst.m_top + 50.0;
			}
			if (m_map[i][j] == 1 || m_map[i][j] == 2 || m_map[i][j] >= 5)
			{
				//��
				BlockDraw(0.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 4)
			{
				BlockDraw(94.0f, 0.0f, &dst, c);
			}
			else if (m_map[i][j] == 0)
			{
				//��
				BlockDraw(47.0f, 0.0f, &dst, c);
			}
		}
	}
}

//BlockDrawMethod�֐�
//�����P�@float	x	:���\�[�X�؂���ʒuX
//�����Q�@float	y	:���\�[�X�؂���ʒuY
//�����R�@RECT_F* dst :�`��ʒu
//�����S�@float	c[]	:�J���[���
//�u���b�N��64*64����`��p�B���\�[�X�؂���ʒu�̂�x,y��
//�ݒ�ł���
void CObjMap1::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 47.0f;
	src.m_bottom = src.m_top + 47.0f;
	//�`��
	Draw::Draw(1, &src, dst, c, 0.0f);
}

/*//BlockHit�ϐ�
//�����P�@float* x			�F������s��object��X�ʒu
//�����Q�@float* y			�F������s��object��Y�ʒu
//�����R�@bool  scroll		�F������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����Afalse=�^���Ȃ��j
//�����S�@bool* up			�F�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T�@bool* down		�F�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U�@bool*left			�F�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V�@bool*right		�F�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W�@float* vx			�F���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//�����X�@float* vy			�F�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10�@int* bt			�F���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N50*50����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈����S�`10�ɕԂ�
void CObjMap1::Map1Hit
(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			if (m_map[i][j] == 1)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*50.0f;
				float by = i*50.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 50.0f > bx) && (*x + (-scroll) < bx + 50.0f) && (*y + (-scrolly) + 50.0f > by) && (*y + (-scrolly) < by + 50.0f))
				{
					//�㉺���E����

					//Vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��������Փ˂��Ă���
							*x = bx + 50.0f + (scroll);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = -(*vx)*0.1f;//-VX*�����W��
						}

						if (r > 45 && r < 135)
						{
							//��
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 50.0f + (scrolly);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̉E�������Փ˂��Ă���
							*x = bx - 50.0f + (scroll);//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
							*y = by + 50.0f + (scrolly);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}
*/
