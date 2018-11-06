//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjHero.h"
#include"UtilityModule.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�ʒu�ύX�p
void CObjHero::SetX(float x)
{
	m_px = x;
}
void CObjHero::SetY(float y)
{
	m_py = y;
}
//�ʒu�擾�p
float CObjHero::GetX()
{
	return m_px;
}
float CObjHero::GetY()
{
	return m_py;
}


//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 368.0f;		//�����ʒu(�����ŕύX�o����)
	m_py = 268.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;


	m_hp = 5;			//����HP�T

	m_posture = 0.0f;	//����(0.0f) ��(1.0f) �E(2.0f) �w��(3.0f)
	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[��
	m_f = true;			//�U������

			//HitBox�쐬���Wx,y�ƃT�C�Yx,y�A�G�������g�ƃI�u�W�F�N�g��ݒ�
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//�x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�U���̓��͔���A�������ςȂ�����
	if (Input::GetVKey('A') == true){
		if (m_f == true) {
			//���I�u�W�F�N�g�쐬		 //�����Ō��ɍ��W�ƌ�����n��
			CObjSword* swd = new CObjSword(m_px, m_py, m_posture);	//���I�u�W�F�N�g�쐬
			Objs::InsertObj(swd, OBJ_SWORD, 3);	//�}�l�[�W���[�ɓo�^

			m_f = false;
		}
	}
	else
		m_f = true;

	//��l���̈ړ��Ƀx�N�g��������
	if (Input::GetVKey(VK_RIGHT) == true)//��
	{
		m_vx += 1.0f;
		m_posture = 2.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_UP) == true)	//��
	{
		m_vy -= 1.0f;
		m_posture = 3.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)//��
	{
		m_vy += 1.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)//��
	{
		m_vx -= 1.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;		
	}

	if (m_ani_time > 6)		//�A�j���[�V��������Ԋu(�������ŃA�j���[�V�������x�ύX�o����)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
		m_ani_frame = 0;	//�t���[��4��0�ɖ߂�

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�ړ��x�N�g�������W�ɉ��Z����(�������ňړ����x�ύX�o����)
	m_px += m_vx * 2.0f;			
	m_py += m_vy * 2.0f;

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	//�e�ۂƐڐG������HP�����炷
	if (0/*hit->CheckObjNameHit(OBJ_BULLET) != nullptr*/)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�N���A�V�[���Ɉړ�
		//Scene::SetScene(new CSceneClear());
	}
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] = { 0,1,2,1, };
	//�`��J���[���@R=RED�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top   =50.0f *  m_posture - 1;		//������-1
	src.m_left  = 0.0f + (AniData[m_ani_frame] * 48);
	src.m_right	=48.0f + (AniData[m_ani_frame] * 48);
	src.m_bottom=50.0f * (m_posture + 1) - 3;	//������-3

				//�\���ʒu�̐ݒ�
	dst.m_top   = 0.0f + m_py;
	dst.m_left	= 0.0f + m_px;
	dst.m_right =32.0f + m_px;
	dst.m_bottom=32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}