Lista 4 - REST

André Campanholo Paschoalini - 14558061
Eduardo Poltroniere da Silva - 16862892
Luiz Felipe Manzoli Franceschini - 16913300
Pedro Hamamoto da Palma - 16818280

	RPC e REST são ambos protocolos de comunicação entre cliente e servidor, utilizados amplamente em aplicações Web. Logo, tais abordagens contemplam duas respostas diferentes para a mesma pergunta fundamental: como organizar a interação entre componentes distribuídos (cliente-servidor).
	O primeiro se baseia em ações, isto é, o cliente chama funções com seus parâmetros remotamente (no servidor) como se fossem locais (em sua máquina). Por outro lado, REST é baseado em recursos: as ações são limitadas (CRUD), o usuário deve conhecer apenas a representação do recurso que ele deseja interagir.
	A interface (API) é definida pelo servidor, e o cliente deve conhecê-la para poder utilizá-la. Portanto, não existem funções para serem invocadas remotamente e parâmetros são passados diretamente na URL. Assim, a interface em aplicações REST é uniforme, o que garante maior escalablidade.
	 